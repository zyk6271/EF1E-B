################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO.c \
../Led.c \
../OSC.c \
../SoftPwm.c \
../SoftSpi.c \
../Work.c \
../config_set.c \
../main.c \
../timer.c 

OBJS += \
./GPIO.o \
./Led.o \
./OSC.o \
./SoftPwm.o \
./SoftSpi.o \
./Work.o \
./config_set.o \
./main.o \
./timer.o 

C_DEPS += \
./GPIO.dep \
./Led.dep \
./OSC.dep \
./SoftPwm.dep \
./SoftSpi.dep \
./Work.dep \
./config_set.dep \
./main.dep \
./timer.dep 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo '正在构建文件： $<'
	@echo '正在调用： C Compiler'
	kf8cc -c -pKF8A200GQS -I"E:\KungFuIDE\include" -I"C:\Users\Rick\Desktop\EF1E\PACK\EF1E-B" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


