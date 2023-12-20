#ifndef BLINDCODEREVIEW_GIT_HPP
#define BLINDCODEREVIEW_GIT_HPP

#include <iostream>
#include <string>
#include <git2.h>
#include <fstream>

namespace git {

    int Error(const git_error* err, int error);

    std::string GetRepoName(const std::string& url);

    int credentials_callback( git_cred** out, const char* url
                       , const char* username_from_url
                       , unsigned int allowed_types, void* payload);

    void CloneByFile(const std::string& path_to_url_file, const std::string& path_to_clone = ".");
    int Clone(const char* url, const char* path);

    int Add(const char* path_to_repo);
    int Commit(const char* path_to_repo, const char* message);
    int Push(const char* path_to_repo);
    int AddCommitPush(const std::string& path_to_repo, const std::string& message);
    int Pull(const char* path_to_repo);
    int Merge(const char* path_to_repo, const char* fetched_commit_hash);

    void PullByFile(std::string& filename);
    void PushByFile(std::string& path_to_file);
} // namespace git


#endif //BLINDCODEREVIEW_GIT_HPP