#include <BlindCodeReview/git.hpp>

namespace git {

    int Push(const char* path_to_repo) {
        git_repository* repo = nullptr;
        git_push_options options = GIT_PUSH_OPTIONS_INIT;
        git_remote* remote = nullptr;
//        const char* refspec = "refs/heads/main";
        const char* refspec = "+refs/heads/main:refs/heads/main"; // force push

        const git_strarray refspecs = {
                const_cast<char**>(&refspec),
                1
        };

        int error = git_repository_open(&repo, path_to_repo);
        if (error != 0) {
            return Error(git_error_last(), error);
        }

        error = git_remote_lookup(&remote, repo, "origin");
        if (error != 0) {
            return Error(git_error_last(), error);
        }

        error = git_push_options_init(&options, GIT_PUSH_OPTIONS_VERSION);
        if (error != 0) {
            return Error(git_error_last(), error);
        }

        options.callbacks.credentials = credentials_callback;

        error = git_remote_push(remote, &refspecs, &options);
        if (error != 0) {
            return Error(git_error_last(), error);
        }

        return 0;
    }

    int AddCommitPush(const std::string& path_to_repo, const std::string& message) {
        Add(path_to_repo.c_str());
        Commit(path_to_repo.c_str(), message.c_str());
        Push(path_to_repo.c_str());

        return 0;
    }

    void PushByFile(std::string& path_to_file) {
        std::ifstream input(path_to_file);
        if (!input.is_open()) {
            throw std::invalid_argument("Cannot open file " + path_to_file);
        }

        std::string repo_url;
        std::string full_path;
        std::string message = "files for review";
        while (input >> repo_url) {
            full_path = "repos/" + GetRepoName(repo_url);
            int result = AddCommitPush(full_path, message);
            if (result) {
                std::cout << "Cannot push " << repo_url << std::endl;
            } else {
                std::cout << "Pushed " << repo_url << std::endl;
            }
        }
    }

} // namespace git