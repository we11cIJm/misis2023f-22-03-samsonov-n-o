#include <BlindCodeReview/git.hpp>

using namespace git;

int main(int argc, char** argv) {
    Git gitt;

    SetPAT("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");
    const char* clone = "--clone";
    const char* push = "--push";
    const char* pull = "--pull";
    const char* dir = "--dir";
    const char* url = "--url";

    std::vector<std::string> urls_vec;
    std::filesystem::path path_to_url_file
            = std::filesystem::exists(std::filesystem::path(std::filesystem::current_path() / "urls.txt")) ?
            std::filesystem::path(std::filesystem::current_path() / "urls.txt") : "";
    std::filesystem::path work_dir = std::filesystem::current_path();

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], dir) == 0) {
            work_dir = argv[i+1];
        }
        if (strcmp(argv[i], url) == 0) {
            path_to_url_file = argv[i+1];

            std::ifstream input(path_to_url_file);
            std::string u;
            while (input >> u) {
                urls_vec.push_back(u);
            }
        }
        if (strcmp(argv[i], clone) == 0) {
            if (std::filesystem::exists(path_to_url_file) && std::filesystem::exists(work_dir)) {
                CloneByFile(path_to_url_file, work_dir);
            } else {
                std::cout << "Provide work directory and path to file with urls" << std::endl;
            }
        }
        else if (strcmp(argv[i], push) == 0) {
            if (std::filesystem::exists(work_dir) && std::filesystem::exists(path_to_url_file)) {
                PushAll(work_dir, urls_vec);
            } else {
                std::cout << "Provide work directory and path to file with urls" << std::endl;
            }
        }
        else if (strcmp(argv[i], pull) == 0) {
            if (std::filesystem::exists(work_dir) && std::filesystem::exists(path_to_url_file)) {
                PullAll(work_dir, urls_vec);
            } else {
                std::cout << "Provide work directory and path to file with urls" << std::endl;
            }
        }
    }

    return 0;
}
