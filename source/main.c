#include <stdinc.h>
void cli_init(int argc, char** argv) {
	struct arg_lit* cp_version = arg_lit0("v", "version", "not implemented");
	struct arg_lit* cp_help = arg_lit0("?", "help", "not implemented");
	struct arg_lit* cp_info = arg_lit0(NULL, "info", "not implemented");
	struct arg_end* cp_end = arg_end(20);
	void* argtable[] = { cp_version, cp_help, cp_info, cp_end };
    int nerrors = arg_parse(argc,argv,argtable);
    if (nerrors > 0) return;
	typedef enum eCurrentFunction {
		ECF_UNDEFINED,
		ECF_VERSION,
		ECF_HELP
	};
	char answers[3];
	answers[ECF_UNDEFINED] = "Unknown command line flag\n";
	answers[ECF_VERSION] = "just - winget version 0.1 (C)2022\n";
	answers[ECF_HELP] = "help goes here\n";
	printf("%d - %d - %d", cp_version->count, cp_help->count, cp_info->count);

}
// todo: linux typecheck macro + parse to structure using this typecheck
int main(int argc, char** argv)
{
	char *test_argv[] = { "justwinget", "--id", "123", "-e"};
	int test_argc = 4;
	//cli_init(test_argc, test_argv);
	cli_cmd_install(test_argc, test_argv);
	return 0;
}
