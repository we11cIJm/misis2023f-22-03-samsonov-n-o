#include <BlindCodeReview/git.hpp>

namespace git {

    int Clone(const char* url, const char* path) {

        git_repository* cloned_repo = nullptr;
        git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;
        git_checkout_options checkout_opts = GIT_CHECKOUT_OPTIONS_INIT;
        int error;

        checkout_opts.checkout_strategy = GIT_CHECKOUT_SAFE;
        clone_opts.checkout_opts = checkout_opts;
        clone_opts.fetch_opts.callbacks.credentials = credentials_callback;

        error = git_clone(&cloned_repo, url, path, &clone_opts);
        if (error != 0) {
            return Error(git_error_last(), error);
        } else if (cloned_repo) {
            git_repository_free(cloned_repo);
        }

        return error;
    }

    void CloneByFile(const std::string& path_to_urls_file, const std::string& path_to_clone /* = "." */) {
        std::ifstream input(path_to_urls_file);
        if (!input.is_open()) {
            throw std::invalid_argument("Cannot open file " + path_to_urls_file);
        }

        std::string url, full_path;
        while (input >> url) {
            full_path = path_to_clone + "repos/" + GetRepoName(url);
            int result = Clone(url.c_str(), full_path.c_str());
            if (result) {
                std::cout << "Cannot clone " << url << std::endl;
            } else {
                std::cout << "Cloned " << url << std::endl;
            }
        }
    }

} // namespace git