#include <BlindCodeReview/git.hpp>

using namespace git;

#ifndef URL
#define URL your_path_to_url
#endif

#ifndef WORK_DIR
#define WORK_DIR your_local_path
#endif

int main(int argc, char** argv) {
    Git gitt;

    size_t numStrings = sizeof(argv) / sizeof(argv[0]);

#ifdef CLONE
    CloneByFile(std::filesystem::path(URL), std::filesystem::path(WORK_DIR));
#endif

    // for our BlindCodeReview programm
#ifdef PUSH
    PushAll(std::filesystem::path(WORK_DIR), std::vector<std::string>({
        "https://github.com/name1/repo_name1", "https://github.com/name2/repo_name2"
    }));
#endif

#ifdef PULL
    PullAll(std::filesystem::path(WORK_DIR), std::vector<std::string>({
        "https://github.com/name1/repo_name1", "https://github.com/name2/repo_name2"
    }));
#endif

    return 0;
}
