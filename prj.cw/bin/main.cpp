#include <BlindCodeReview/git.hpp>

using namespace git;

std::string url = "https://github.com/we11cIJm/testrepo.git";

int main(int argc, char** argv) {
    git_libgit2_init();
    std::string filename = "../urls.txt";
    std::string clone = "--clone";
    std::string push = "--push";
    std::string push_l = "-p";
    std::string pull = "--pull";

    if (argc < 2) {
        std::cout << "Nothing is called\n";
        git_libgit2_shutdown();
        return 0;
    }
    if (argv[1] == push_l) {
        Add("testrepo");
        Commit("testrepo", "files for review");
        Push("testrepo");
    }
    else if (argv[1] == clone) {
        CloneByFile(filename, "/home/kolya/Desktop/code");
        std::cout << "Clone is called\n";
    }
    else if (argv[1] == push) {
        AddCommitPush(filename, "files for review");
        std::cout << "Push is called\n";
    }

    else if (argv[1] == pull) {
        PullByFile(filename);
        std::cout << "Pull is called\n";
    } else {
        std::cout << "Other is called\n";
    }

    git_libgit2_shutdown();
    return 0;
}