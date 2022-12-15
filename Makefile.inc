mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))
APPL_COBJS += \
  ScenarioTracerWithStarter.o\
  ScenarioTracer.o\
  Scenario.o\
  SimpleTimer.o\
  Starter.o\
  Walker.o
APPL_LIBS += -lm
APPL_DIRS += \
  $(mkfile_path)/app\
  $(mkfile_path)/unit
INCLUDES += \
  -I$(mkfile_path)/app\
  -I$(mkfile_path)/unit
