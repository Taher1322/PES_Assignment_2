##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PES_Assignment_2
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/ujjai/Documents/PES_Assignment_2
ProjectPath            :=C:/Users/ujjai/Documents/PES_Assignment_2/PES_Assignment_2
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ujjai
Date                   :=14/09/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=gcc
SharedObjectLinkerName :=C:/MinGW/bin/gcc.exe
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="PES_Assignment_2.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/gcc.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/llfifo.c$(ObjectSuffix) $(IntermediateDirectory)/test_llfifo.c$(ObjectSuffix) $(IntermediateDirectory)/test_cbfifo.c$(ObjectSuffix) $(IntermediateDirectory)/cbfifo.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(ConfigurationName)"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(ConfigurationName)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM main.c
	$(CC) $(SourceSwitch) "C:/Users/ujjai/Documents/PES_Assignment_2/PES_Assignment_2/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) main.c

$(IntermediateDirectory)/llfifo.c$(ObjectSuffix): llfifo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/llfifo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/llfifo.c$(DependSuffix) -MM llfifo.c
	$(CC) $(SourceSwitch) "C:/Users/ujjai/Documents/PES_Assignment_2/PES_Assignment_2/llfifo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/llfifo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/llfifo.c$(PreprocessSuffix): llfifo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/llfifo.c$(PreprocessSuffix) llfifo.c

$(IntermediateDirectory)/test_llfifo.c$(ObjectSuffix): test_llfifo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_llfifo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_llfifo.c$(DependSuffix) -MM test_llfifo.c
	$(CC) $(SourceSwitch) "C:/Users/ujjai/Documents/PES_Assignment_2/PES_Assignment_2/test_llfifo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_llfifo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_llfifo.c$(PreprocessSuffix): test_llfifo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_llfifo.c$(PreprocessSuffix) test_llfifo.c

$(IntermediateDirectory)/test_cbfifo.c$(ObjectSuffix): test_cbfifo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test_cbfifo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test_cbfifo.c$(DependSuffix) -MM test_cbfifo.c
	$(CC) $(SourceSwitch) "C:/Users/ujjai/Documents/PES_Assignment_2/PES_Assignment_2/test_cbfifo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test_cbfifo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test_cbfifo.c$(PreprocessSuffix): test_cbfifo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test_cbfifo.c$(PreprocessSuffix) test_cbfifo.c

$(IntermediateDirectory)/cbfifo.c$(ObjectSuffix): cbfifo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cbfifo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/cbfifo.c$(DependSuffix) -MM cbfifo.c
	$(CC) $(SourceSwitch) "C:/Users/ujjai/Documents/PES_Assignment_2/PES_Assignment_2/cbfifo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cbfifo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cbfifo.c$(PreprocessSuffix): cbfifo.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cbfifo.c$(PreprocessSuffix) cbfifo.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


