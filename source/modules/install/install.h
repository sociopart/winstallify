// ----------------- INSTALL COMMAND ----------------- //
#ifndef INSTALL_H
#define INSTALL_H
#include <stdinc.h>
typedef struct _install_cli_data {
	char* manifest_path;
	char* id;
	char* name;
	char* moniker;
	char* version;
	char* source;
	char* scope;
	int   architecture;
	bool  is_exact;
	bool  is_interactive;
	bool  is_silent;
	char* locale_code;
	char* log_path;
	char* override_args;
	char* install_location;
	bool  is_force_rehash;
	char* dependency_source;
	bool  is_pkg_agr_accepted;
	char* rest_http_header;
	bool  is_src_agr_accepted;
	char* installed_filename;
	bool  is_verbose_log_enabled;
} installCLIData;
// --------------------------------------------------- //
//static cli_menu_page install_menu_page = {"install", cli_cmd_install};
int cli_cmd_install(int cm_argc, char** cm_argv);
#endif
