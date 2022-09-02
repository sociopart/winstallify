typedef enum eInstallModes {
	IM_UNDEFINED = -1,
	IM_INTERACTIVE,
	IM_SILENT,
	IM_SILENTWITHPROGRESS
};

typedef enum ePCArchitecture {
	ARCH_UNDEFINED = -1,
	ARCH_X86,
	ARCH_X64,
	ARCH_ARM,
	ARCH_ARM64,
	ARCH_NEUTRAL
};

typedef enum eInstallerType {

};

typedef struct sAppsAndFeaturesEntry {

};

typedef struct sInstaller {
	sAppsAndFeaturesEntry** installer_entries;
	ePCArchitecture installer_arch;
	char* installer_sha256;
	eInstallerType installer_type;
	char* installer_url;
};
typedef char* not_impl_yet;

typedef struct sManifestData {
	
};