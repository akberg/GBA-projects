# Microsoft Developer Studio Project File - Name="tank" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=tank - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "tank.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "tank.mak" CFG="tank - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "tank - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "tank - Win32 Debug" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "tank - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Cmd_Line "NMAKE /f tank.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "tank.exe"
# PROP BASE Bsc_Name "tank.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Cmd_Line "nmake /f "tank.mak""
# PROP Rebuild_Opt "/a"
# PROP Target_File "tank.bin"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "tank - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Cmd_Line "NMAKE /f tank.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "tank.exe"
# PROP BASE Bsc_Name "tank.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Cmd_Line "nmake /f "tank.mak""
# PROP Rebuild_Opt "/a"
# PROP Target_File "tank.bin"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "tank - Win32 Release"
# Name "tank - Win32 Debug"

!IF  "$(CFG)" == "tank - Win32 Release"

!ELSEIF  "$(CFG)" == "tank - Win32 Debug"

!ENDIF 

# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\gfx.c
# End Source File
# Begin Source File

SOURCE=.\main.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\gba.h
# End Source File
# Begin Source File

SOURCE=.\gfx.h
# End Source File
# Begin Source File

SOURCE=.\keypad.h
# End Source File
# Begin Source File

SOURCE=.\gfx\logo.h
# End Source File
# Begin Source File

SOURCE=.\gfx\objects.h
# End Source File
# Begin Source File

SOURCE=.\screenmode.h
# End Source File
# Begin Source File

SOURCE=.\gfx\star.h
# End Source File
# Begin Source File

SOURCE=.\gfx\tank.h
# End Source File
# Begin Source File

SOURCE=.\gfx\text.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\make.bat
# End Source File
# Begin Source File

SOURCE=.\readme.txt
# End Source File
# Begin Source File

SOURCE=.\tank.mak
# End Source File
# End Group
# End Target
# End Project
