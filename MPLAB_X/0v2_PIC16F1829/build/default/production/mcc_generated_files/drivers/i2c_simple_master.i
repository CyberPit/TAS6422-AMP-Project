# 1 "mcc_generated_files/drivers/i2c_simple_master.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/Applications/microchip/mplabx/v5.40/packs/Microchip/PIC12-16F1xxx_DFP/1.2.63/xc8/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "mcc_generated_files/drivers/i2c_simple_master.c" 2
# 27 "mcc_generated_files/drivers/i2c_simple_master.c"
# 1 "mcc_generated_files/drivers/.././i2c1_master.h" 1
# 54 "mcc_generated_files/drivers/.././i2c1_master.h"
# 1 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdio.h" 1 3



# 1 "/Applications/microchip/xc8/v2.20/pic/include/c99/musl_xc8.h" 1 3
# 5 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdio.h" 2 3





# 1 "/Applications/microchip/xc8/v2.20/pic/include/c99/features.h" 1 3
# 11 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdio.h" 2 3
# 24 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdio.h" 3
# 1 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 1 3





typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 122 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef unsigned size_t;
# 137 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef long ssize_t;
# 168 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef __int24 int24_t;
# 204 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 246 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef long long off_t;
# 399 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 25 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdio.h" 2 3
# 52 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);

#pragma printf_check(printf) const
#pragma printf_check(vprintf) const
#pragma printf_check(sprintf) const
#pragma printf_check(snprintf) const
#pragma printf_check(vsprintf) const
#pragma printf_check(vsnprintf) const

int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 54 "mcc_generated_files/drivers/.././i2c1_master.h" 2

# 1 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdint.h" 1 3
# 22 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdint.h" 3
# 1 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 1 3
# 127 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef long intptr_t;
# 158 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 173 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef long int32_t;





typedef long long int64_t;
# 188 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 209 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 23 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 139 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdint.h" 3
# 1 "/Applications/microchip/xc8/v2.20/pic/include/c99/bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 140 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdint.h" 2 3
# 55 "mcc_generated_files/drivers/.././i2c1_master.h" 2

# 1 "/Applications/microchip/xc8/v2.20/pic/include/c99/stdbool.h" 1 3
# 56 "mcc_generated_files/drivers/.././i2c1_master.h" 2


typedef enum {
    I2C1_NOERR,
    I2C1_BUSY,
    I2C1_FAIL


} i2c1_error_t;

typedef enum
{
    I2C1_STOP=1,
    I2C1_RESTART_READ,
    I2C1_RESTART_WRITE,
    I2C1_CONTINUE,
    I2C1_RESET_LINK
} i2c1_operations_t;

typedef uint8_t i2c1_address_t;
typedef i2c1_operations_t (*i2c1_callback_t)(void *funPtr);


i2c1_operations_t I2C1_CallbackReturnStop(void *funPtr);
i2c1_operations_t I2C1_CallbackReturnReset(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartWrite(void *funPtr);
i2c1_operations_t I2C1_CallbackRestartRead(void *funPtr);






void I2C1_Initialize(void);
# 101 "mcc_generated_files/drivers/.././i2c1_master.h"
i2c1_error_t I2C1_Open(i2c1_address_t address);
# 111 "mcc_generated_files/drivers/.././i2c1_master.h"
i2c1_error_t I2C1_Close(void);
# 123 "mcc_generated_files/drivers/.././i2c1_master.h"
i2c1_error_t I2C1_MasterOperation(_Bool read);




i2c1_error_t I2C1_MasterWrite(void);




i2c1_error_t I2C1_MasterRead(void);
# 142 "mcc_generated_files/drivers/.././i2c1_master.h"
void I2C1_SetTimeout(uint8_t timeOut);
# 152 "mcc_generated_files/drivers/.././i2c1_master.h"
void I2C1_SetBuffer(void *buffer, size_t bufferSize);
# 164 "mcc_generated_files/drivers/.././i2c1_master.h"
void I2C1_SetDataCompleteCallback(i2c1_callback_t cb, void *ptr);
# 174 "mcc_generated_files/drivers/.././i2c1_master.h"
void I2C1_SetWriteCollisionCallback(i2c1_callback_t cb, void *ptr);
# 184 "mcc_generated_files/drivers/.././i2c1_master.h"
void I2C1_SetAddressNackCallback(i2c1_callback_t cb, void *ptr);
# 194 "mcc_generated_files/drivers/.././i2c1_master.h"
void I2C1_SetDataNackCallback(i2c1_callback_t cb, void *ptr);
# 204 "mcc_generated_files/drivers/.././i2c1_master.h"
void I2C1_SetTimeoutCallback(i2c1_callback_t cb, void *ptr);
# 213 "mcc_generated_files/drivers/.././i2c1_master.h"
void (*MSSP1_InterruptHandler)(void);
# 222 "mcc_generated_files/drivers/.././i2c1_master.h"
void I2C1_SetInterruptHandler(void (* InterruptHandler)(void));
# 27 "mcc_generated_files/drivers/i2c_simple_master.c" 2

# 1 "mcc_generated_files/drivers/i2c_simple_master.h" 1
# 36 "mcc_generated_files/drivers/i2c_simple_master.h"
uint8_t i2c_read1ByteRegister(i2c1_address_t address, uint8_t reg);
uint16_t i2c_read2ByteRegister(i2c1_address_t address, uint8_t reg);
void i2c_write1ByteRegister(i2c1_address_t address, uint8_t reg, uint8_t data);
void i2c_write2ByteRegister(i2c1_address_t address, uint8_t reg, uint16_t data);

void i2c_writeNBytes(i2c1_address_t address, void* data, size_t len);
void i2c_readDataBlock(i2c1_address_t address, uint8_t reg, void *data, size_t len);
void i2c_readNBytes(i2c1_address_t address, void *data, size_t len);
# 28 "mcc_generated_files/drivers/i2c_simple_master.c" 2



static i2c1_operations_t wr1RegCompleteHandler(void *p)
{
    I2C1_SetBuffer(p,1);
    I2C1_SetDataCompleteCallback(((void*)0),((void*)0));
    return I2C1_CONTINUE;
}

void i2c_write1ByteRegister(i2c1_address_t address, uint8_t reg, uint8_t data)
{
    while(!I2C1_Open(address));
    I2C1_SetDataCompleteCallback(wr1RegCompleteHandler,&data);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(((void*)0),((void*)0));
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close());
}

void i2c_writeNBytes(i2c1_address_t address, void* data, size_t len)
{
    while(!I2C1_Open(address));
    I2C1_SetBuffer(data,len);
    I2C1_SetAddressNackCallback(((void*)0),((void*)0));
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close());
}


static i2c1_operations_t rd1RegCompleteHandler(void *p)
{
    I2C1_SetBuffer(p,1);
    I2C1_SetDataCompleteCallback(((void*)0),((void*)0));
    return I2C1_RESTART_READ;
}

uint8_t i2c_read1ByteRegister(i2c1_address_t address, uint8_t reg)
{
    uint8_t d2=42;
    i2c1_error_t e;
    int x;

    for(x = 2; x != 0; x--)
    {
        while(!I2C1_Open(address));
        I2C1_SetDataCompleteCallback(rd1RegCompleteHandler,&d2);
        I2C1_SetBuffer(&reg,1);
        I2C1_SetAddressNackCallback(((void*)0),((void*)0));
        I2C1_MasterWrite();
        while(I2C1_BUSY == (e = I2C1_Close()));
        if(e==I2C1_NOERR) break;
    }


    return d2;
}


static i2c1_operations_t rd2RegCompleteHandler(void *p)
{
    I2C1_SetBuffer(p,2);
    I2C1_SetDataCompleteCallback(((void*)0),((void*)0));
    return I2C1_RESTART_READ;
}

uint16_t i2c_read2ByteRegister(i2c1_address_t address, uint8_t reg)
{

    uint16_t result;

    while(!I2C1_Open(address));
    I2C1_SetDataCompleteCallback(rd2RegCompleteHandler,&result);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(((void*)0),((void*)0));
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close());

    return (result << 8 | result >> 8);
}


static i2c1_operations_t wr2RegCompleteHandler(void *p)
{
    I2C1_SetBuffer(p,2);
    I2C1_SetDataCompleteCallback(((void*)0),((void*)0));
    return I2C1_CONTINUE;
}

void i2c_write2ByteRegister(i2c1_address_t address, uint8_t reg, uint16_t data)
{
    while(!I2C1_Open(address));
    I2C1_SetDataCompleteCallback(wr2RegCompleteHandler,&data);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(((void*)0),((void*)0));
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close());
}


typedef struct
{
    size_t len;
    char *data;
}buf_t;

static i2c1_operations_t rdBlkRegCompleteHandler(void *p)
{
    I2C1_SetBuffer(((buf_t *)p)->data,((buf_t*)p)->len);
    I2C1_SetDataCompleteCallback(((void*)0),((void*)0));
    return I2C1_RESTART_READ;
}

void i2c_readDataBlock(i2c1_address_t address, uint8_t reg, void *data, size_t len)
{

    buf_t d;
    d.data = data;
    d.len = len;

    while(!I2C1_Open(address));
    I2C1_SetDataCompleteCallback(rdBlkRegCompleteHandler,&d);
    I2C1_SetBuffer(&reg,1);
    I2C1_SetAddressNackCallback(((void*)0),((void*)0));
    I2C1_MasterWrite();
    while(I2C1_BUSY == I2C1_Close());
}

void i2c_readNBytes(i2c1_address_t address, void *data, size_t len)
{
    while(!I2C1_Open(address));
    I2C1_SetBuffer(data,len);
    I2C1_MasterRead();
    while(I2C1_BUSY == I2C1_Close());
}
