#include "install.h"

int cli_cmd_install(int cm_argc, char** cm_argv) {
    printf("MAIN PAGE: install\n");
    installCLIData install_data;
    void* argtable[][2] =
    {
        {
            arg_str0("m", "manifest", "<char>", "not implemented"),
            (void**)&install_data.manifest_path
        },
        {
            arg_str0(NULL, "id", "<char>", "not implemented"),
            (void**)&install_data.id
        },
        {
            arg_str0(NULL, "name", "<char>", "not implemented"),
            (void**)&install_data.name
        },
        {
            arg_str0(NULL, "moniker","<char>", "not implemented"),
            (void**)&install_data.moniker
        },
        {
            arg_str0("v", "version", "<char>","not implemented"),
            (void**)&install_data.version
        },
        {
            arg_str0("s", "source", "<char>", "not implemented"),
            (void**)&install_data.source
        },
        {
            arg_str0(NULL, "scope", "<char>", "not implemented"),
            (void**)&install_data.scope
        },
        {
            arg_str0("a", "architecture", "<char>", "not implemented"),
            (void**)&install_data.architecture
        },
        {
            arg_lit0("e", "exact", "not implemented"),
            (void*)&install_data.is_exact
        },
        {
            arg_lit0("i", "interactive", "not implemented"),
            (void*)&install_data.is_interactive
        },
        {
            arg_lit0("h", "silent", "not implemented"),
            (void*)&install_data.is_silent
        },
        {
            arg_str0(NULL, "locale", "<char>","not implemented"),
            (void**)&install_data.locale_code
        },
        {
            arg_str0("o", "log", "<char>", "not implemented"),
            (void**)&install_data.log_path
        },
        {
            arg_str0(NULL, "override", "<char>", "not implemented"),
            (void**)&install_data.override_args
        },
        {
            arg_str0("l", "location", "<char>", "not implemented"),
            (void**)&install_data.install_location
        },
        {
            arg_lit0(NULL, "force", "not implemented"),
            (void*)&install_data.is_force_rehash
        },
        {
            arg_str0(NULL, "dependency-source", "<char>", "not implemented"),
            (void**)&install_data.dependency_source
        },
        {
            arg_lit0(NULL, "accept-package-agreements", "not implemented"),
            (void*)&install_data.is_pkg_agr_accepted
        },
        {
            arg_str0(NULL, "header", "<char>", "not implemented"),
            (void**)&install_data.rest_http_header
        },
        {
            arg_lit0(NULL, "accept-source-agreements", "not implemented"),
            (void*)&install_data.is_src_agr_accepted
        },
        {
            arg_str0("r", "rename", "<char>", "not implemented"),
            (void**)&install_data.installed_filename
        },
        {
            arg_lit0(NULL, "verbose-logs", "not implemented"),
            (void*)&install_data.is_verbose_log_enabled
        },
        {
            arg_end(20),
            (void*) NULL
        },
        { 0, 0 }
    };

    cli_parse_ext(cm_argc, cm_argv, &argtable, true);
    install_app(install_data);
    return 0;
}
