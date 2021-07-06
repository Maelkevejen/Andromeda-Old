# ::build::includes::includes.bzl

"""
    Bazel Build Tools
"""

load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")
load("@bazel_skylib//lib:paths.bzl", "paths")

def configure_submodule_dependencies(repo_alias = "@andromeda", repo_path = "./"):
    """
        Compiles from binary submodule dependencies of various types: Bazel, CMake, Make, etc.

        Args:
            repo_alias: The location of the owning repo
            repo_path: The path location of the owning repo

            If no configuration is provided, the default arguments will be used: {"@andromeda", "./"}
    """
    maybe(
        native.local_repository,
        name = "gtest",
        path = paths.join(repo_path, "includes/gtest"),
    )

    maybe(
        native.new_local_repository,
        name = "glfw",
        build_file = repo_alias + "//:build/includes/glfw/BUILD.bazel",
        path = paths.join(repo_path, "includes/glfw"),
    )

    maybe(
        native.new_local_repository,
        name = "spdlog",
        build_file = repo_alias + "//:build/includes/spdlog/BUILD.bazel",
        path = paths.join(repo_path, "includes/spdlog"),
    )
