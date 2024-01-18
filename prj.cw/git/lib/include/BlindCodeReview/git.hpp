#ifndef BLINDCODEREVIEW_GIT_HPP
#define BLINDCODEREVIEW_GIT_HPP

#include <iostream>
#include <string>
#include <git2.h>
#include <fstream>
#include <array>
#include <chrono>
#include <stdexcept>
#include <filesystem>
#include <cstring>
#include <cassert>
#include <vector>

//#ifdef PAT
//#define PAT "ghp_************************************" // insert your token here
//#endif

namespace git {
    extern const char* PAT;

    void SetPAT(const char* value);

    /**
     * \brief A class representing the Git library initialization and cleanup.
     *
     * This class initializes the Git library in its constructor and
     * shuts it down in its destructor.
     */
    class Git {
    public:
        /**
         * \brief Constructor to initialize the Git library.
         */
        Git() {
            git_libgit2_init();
        }

        /**
         * \brief Destructor to shut down the Git library.
         */
        ~Git() {
            git_libgit2_shutdown();
        }
    };

    int Error(const git_error* err, int error, const std::filesystem::path& local_path, const std::filesystem::path& repo_name);

    void CleanUp( git_repository* repo = nullptr, git_index* index = nullptr
            , git_tree* tree = nullptr, git_object* object = nullptr
            , git_reference* local_ref = nullptr, git_reference* remote_ref = nullptr
            , git_signature* signature = nullptr, git_remote* remote = nullptr
            , git_strarray* arr = nullptr, git_commit* local_commit = nullptr
            , git_commit* remote_commit = nullptr
            , git_annotated_commit* local_annotated_commit = nullptr
            , git_annotated_commit* remote_annotated_commit = nullptr);

    std::string GetRepoName(const std::string& url);

    int CredentialsCallback( git_cred** out, const char* url
            , const char* username_from_url
            , unsigned int allowed_types, void* payload);

    int Clone(const char* url, const std::filesystem::path& work_dir);

    void Check(git_repository* repo, const std::filesystem::path& local_path_to_repo);

    int Add(const std::filesystem::path& local_path_to_repo);

    int Commit(const std::filesystem::path& local_path_to_repo, const char* message);

    int Push(const std::filesystem::path& local_path_to_repo);

    int AddCommitPush(const std::filesystem::path& local_path_to_repo, const std::string& message);

    int Pull(const std::filesystem::path& local_path_to_repo);

    int Fetch(const std::filesystem::path& local_path_to_repo);

    int Merge(const std::filesystem::path& local_path_to_repo);

    /**
     * \fn void CloneByFile(const std::filesystem::path& path_to_urls_file, const std::filesystem::path& local_path = ".")
     * \brief Clone repositories listed in a file to a local directory.
     *
     * This function reads a file containing Git repository URLs and
     * clones each repository to the specified local directory.
     *
     * \param path_to_urls_file The path to the file containing repository URLs.
     * \param local_path The local directory where repositories will be cloned.
     */
    void CloneByFile(const std::filesystem::path& path_to_urls_file, const std::filesystem::path& local_path = ".");

    /**
     * \fn void PullAll(const std::filesystem::path& path_to_all_repos, const std::vector<std::string>& urls)
     * \brief Pull updates from multiple repositories.
     *
     * This function iterates through a list of Git repository URLs and pulls
     * updates for each repository.
     *
     * \param path_to_all_repos The path to the file containing repository URLs.
     * \param urls A vector of Git repository URLs.
     */
    void PullAll(const std::filesystem::path& path_to_all_repos, const std::vector<std::string>& urls);

    /**
     * \fn void PushAll(const std::filesystem::path& path_to_all_repos, const std::vector<std::string>& urls)
     * \brief Push updates to multiple repositories.
     *
     * This function iterates through a list of Git repository URLs and pushes
     * updates for each repository.
     *
     * \param path_to_all_repos The path to the file containing repository URLs.
     * \param urls A vector of Git repository URLs.
     */
    void PushAll(const std::filesystem::path& path_to_all_repos, const std::vector<std::string>& urls);

    void PrintProgressBar(int32_t total_repos_count, int32_t current_repo_pos = 0);

} // namespace git

namespace help_stuff {
    struct MergeOptions {
        const char** heads;
        size_t heads_count;
        git_annotated_commit **annotated;
        size_t annotated_count;
    };

    std::pair<const git_oid*, const git_oid*> GetLastCommits(git_repository* repo);

    int UpdateCallback(const char* refname, const git_oid* a, const git_oid* b, void* data);

    void MergeOptionsInit(struct MergeOptions* opts);

    int ResolveRefish(git_annotated_commit** commit, git_repository* repo, const char* refish);

    int ResolveHeads(git_repository* repo, struct MergeOptions* opts);

    int PerformFastforward(git_repository* repo, const git_oid* target_oid, int is_unborn);

    int CreateMergeCommit(git_repository* repo, git_index* index, struct MergeOptions* opts);

    void* Xrealloc(void* oldp, size_t newsz);

    void OptsAddRefish(struct MergeOptions* opts, const char* refish);

} // namespace help_functions

#endif //BLINDCODEREVIEW_GIT_HPP
