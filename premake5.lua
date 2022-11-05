-- Premake5 file --

----------------------------------------------------------------------------
-- Functions block --
-- Makes a path relative to the folder containing this script file. --
ROOT_PATH = function(path)
  return string.format("%s/%s", _MAIN_SCRIPT_DIR, path)
end
-- Makes a path relative to the project directory. --
PROJ_PATH = function(path)
  return string.format("%s/%s", PROJ_DIR, path)
end

-- Clean Function --
newaction {
 trigger     = "clean",
 description = "clean the software",
 execute     = function ()
    print("Clean the build...")
    for i = 1, (#CLEANUP_DIRS) do
  os.rmdir(CLEANUP_DIRS[i])
  end
  for i = 1, (#CLEANUP_EXTS) do
  os.remove(CLEANUP_EXTS[i])
  end
    print("Done.")
 end
}
----------------------------------------------------------------------------
-- Setting project data --
PROJ_KIND      = "ConsoleApp"
PROJ_LANGUAGE  = "C"
WORKSPACE_NAME = "winstallify"
PROJ_DIR       = ROOT_PATH "/source"
START_PROJECT  = "winstallify-cli"
CHARACTER_SET  = "ASCII"


-- Resources data path to tell IDE where are them --
-- Useful while debugging program --
USING_DIRS = {}

-- Include source directories --
INCLUDE_DIRS = {
  ROOT_PATH "/include/**.h",
  ROOT_PATH "/source/",
  ROOT_PATH "/include/argtable/"
}

-- Directories with .LIB files (to link with current project) --
LIB_DIRS = {}

-- Directories where the source is located --
FILE_DIRS = {
  ROOT_PATH "/source/**",
  ROOT_PATH "/include/**.c"
}

-- Libs that should be linked during compilation process --
LINKED_LIBS = {}

-- Files and directories that should be cleaned up --
-- (such as generated solution files, etc.) --
CLEANUP_EXTS = {
  ----------- MSVC 2019 -----------
  PROJ_PATH "/**.vcxproj",
  PROJ_PATH "/**.vcxproj.user",
  PROJ_PATH "/**.vcxproj.filters",
  PROJ_PATH "/../**.sln"
  ---------------------------------
}

CLEANUP_DIRS = {
  ----------- MSVC 2019 -----------
  PROJ_PATH "/../bin",
  PROJ_PATH "/../obj",
  PROJ_PATH "/../.vs"
  ---------------------------------
}
----------------------------------------------------------------------------
-- Setting workspace and configurations -- 
workspace (WORKSPACE_NAME)
  -- Workspace stuff which is global to all configurations -- 
  configurations { "Debug", "Release" }

platforms { "x86_64", "x86" }

  filter "platforms:x86_64"
      architecture "x86_64"
  filter "platforms:x86"
      architecture "x86"
  ------------------------------------
  project (START_PROJECT)
      kind (PROJ_KIND)
      language (PROJ_LANGUAGE)
      location (PROJ_DIR)
  characterset (CHARACTER_SET)
  files{FILE_DIRS}
  targetdir "release/bin/%{cfg.buildcfg}"
      objdir "release/obj/%{cfg.buildcfg}"
      links{LINKED_LIBS}
      includedirs{INCLUDE_DIRS}
      libdirs{LIB_DIRS}
  usingdirs{USING_DIRS}
  
      filter "configurations:debug"
          defines { "DEBUG" }
          runtime  "debug"
          symbols  "on"
          optimize "off"
      filter "configurations:release"
          defines { "NDEBUG" }
          runtime  "release"
          symbols  "off"
          optimize "on"
--------------------------------------
