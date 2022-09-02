#ifndef MODULES_H
#define MODULES_H
#include <stdinc.h>
typedef struct _cli_menu_page{
	const char* page_name;
	int (*func_name) (int, char**);
} cli_menu_page;
void cli_init(int argc, char** argv);
int cli_cmd_install(int cm_argc, char** cm_argv);


static cli_menu_page menu_pages[] = {
    { "install",      cli_cmd_install      },
	{ 0, 0 }
};

//menu_pages[0] = { "install",   cli_cmd_install};

//menu_pages[2] = {
    //,
	/*{ "show",      cli_cmd_show      },
	{ "source",    cli_cmd_source    },
	{ "search",    cli_cmd_search    },
	{ "list",      cli_cmd_list      },
	{ "upgrade",   cli_cmd_upgrade   },
	{ "uninstall", cli_cmd_uninstall },
	{ "hash",      cli_cmd_hash      },
	{ "validate",  cli_cmd_validate  },
	{ "settings",  cli_cmd_settings  },
	{ "features",  cli_cmd_features  },
	{ "export",    cli_cmd_export    },
	{ "import",    cli_cmd_import    },*/
	//{0, 0}
//};
#endif

//int cli_cmd_show(int cm_argc, char** cm_argv);
//int cli_cmd_source(int cm_argc, char** cm_argv);
//int cli_cmd_search(int cm_argc, char** cm_argv);
//int cli_cmd_list(int cm_argc, char** cm_argv);
//int cli_cmd_upgrade(int cm_argc, char** cm_argv);
//int cli_cmd_uninstall(int cm_argc, char** cm_argv);
//int cli_cmd_hash(int cm_argc, char** cm_argv);
//int cli_cmd_validate(int cm_argc, char** cm_argv);
//int cli_cmd_settings(int cm_argc, char** cm_argv);
//int cli_cmd_features(int cm_argc, char** cm_argv);
//int cli_cmd_export(int cm_argc, char** cm_argv);
//int cli_cmd_import(int cm_argc, char** cm_argv);
//
