# ::build::includes::includes.bzl

load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
load("@bazel_skylib//lib:paths.bzl", "paths")

def configure_submodule_dependencies(repo_alias = "@andromeda", repo_path = "./"):
    maybe(
        native.local_repository,
        name = "gtest",
        path = paths.join(repo_path, "includes/gtest"),
    )
