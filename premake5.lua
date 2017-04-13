-- premake5.lua
workspace "Assignment4"
   configurations { "Debug", "Release" }

project "Assignment4"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "**.h", "**.cpp" }
   buildoptions {"-std=c++11", "-g"}


   filter "configurations:Debug"
      defines { "DEBUG" }
      flags { "Symbols" }

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

   newaction
   {
       trigger     = "docs",
       description = "Build documentation",
       execute = function ()
           if os.get() == "macosx" then
               os.execute "doxygen doxygen.config && open docs/html/index.html"
           else
               os.execute "doxygen doxygen.config"
           end
       end
   }
