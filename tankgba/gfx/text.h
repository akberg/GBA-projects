/**********************************************
*       text.h                                   
**********************************************/
// has two images txstartData[] 82x14, and also txdiedData[] 82x14

#define  txstart_WIDTH   82
#define  txstart_HEIGHT  14


const u16 txstartData[] = {
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0xFF00,
                    0x00FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0x0000,
                    0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFF00, 0x00FF, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0x0000, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x00FF, 0xFFFF,
                    0xFF00, 0xFFFF, 0x0000, 0xFF00, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0xFFFF, 0x00FF,
                    0x0000, 0xFF00, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,
                    0x0000, 0xFF00, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0xFFFF, 0xFFFF, 0x00FF, 0xFF00,
                    0x00FF, 0xFFFF, 0x00FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000,
                    0xFFFF, 0x00FF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF,
                    0x00FF, 0xFF00, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0xFFFF,
                    0xFFFF, 0x00FF, 0xFF00, 0xFFFF, 0xFFFF, 0x00FF, 0xFF00, 0xFFFF, 0xFFFF, 0x00FF,
                    0xFF00, 0xFFFF, 0xFF00, 0x00FF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x00FF,
                    0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFF00, 0xFFFF, 0x0000, 0xFFFF, 0xFF00, 0xFFFF,
                    0x0000, 0x0000, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0xFF00, 0xFFFF, 0x0000, 0xFF00, 0x00FF, 0x0000, 0xFFFF, 0x00FF, 0xFF00,
                    0x00FF, 0xFF00, 0x00FF, 0xFF00, 0x00FF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000,
                    0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFF00, 0x00FF, 0xFF00, 0x00FF, 0xFF00,
                    0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFF00, 0x00FF, 0x0000, 0xFFFF, 0x0000,
                    0xFF00, 0x00FF, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF,
                    0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFF00, 0x00FF, 0xFFFF, 0x0000,
                    0x0000, 0xFFFF, 0xFFFF, 0x00FF, 0xFF00, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0xFF00, 0x00FF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFF00, 0x00FF, 0x0000, 0xFFFF,
                    0x0000, 0xFF00, 0x00FF, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000,
                    0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFF00, 0xFFFF, 0x0000,
                    0xFF00, 0x0000, 0x0000, 0xFF00, 0x00FF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000,
                    0x0000, 0xFF00, 0x00FF, 0x0000, 0xFF00, 0xFFFF, 0x0000, 0xFF00, 0x00FF, 0x0000,
                    0xFFFF, 0x0000, 0xFF00, 0x00FF, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF,
                    0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFF00, 0xFFFF,
                    0xFFFF, 0xFFFF, 0xFF00, 0xFFFF, 0xFFFF, 0x00FF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000,
                    0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0xFF00, 0x00FF,
                    0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x00FF, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000,
                    0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0xFF00, 0xFFFF, 0x00FF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFF00, 0xFFFF, 0x00FF,
                    0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0xFF00,
                    0x00FF, 0x0000, 0xFF00, 0xFFFF, 0x00FF, 0xFFFF, 0xFF00, 0x00FF, 0x0000, 0x0000,
                    0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000,};

#define  txdied_WIDTH   82
#define  txdied_HEIGHT  14


const u16 txdiedData[] = {
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFF00, 0x00FF, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFF00, 0x00FF,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0x00FF, 0x0000, 0xFFFF,
                    0x00FF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0x00FF, 0x0000,
                    0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFF00, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000,
                    0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF,
                    0xFF00, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x00FF, 0x0000, 0xFFFF, 0x0000, 0xFF00,
                    0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFF00, 0x00FF, 0x0000,
                    0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF,
                    0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0xFFFF, 0xFF00, 0x00FF, 0x0000, 0xFF00, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000,
                    0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF,
                    0x0000, 0xFFFF, 0x0000, 0xFF00, 0xFFFF, 0xFFFF, 0x00FF, 0xFF00, 0xFFFF, 0xFFFF,
                    0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0xFF00, 0xFFFF, 0x00FF, 0x0000, 0xFFFF, 0x0000, 0xFF00, 0x00FF, 0xFFFF,
                    0x0000, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x00FF, 0xFF00, 0x00FF, 0xFFFF, 0x00FF,
                    0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0xFF00, 0xFFFF, 0x00FF, 0x0000, 0xFFFF, 0x0000, 0xFF00, 0x00FF,
                    0xFFFF, 0x0000, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000,
                    0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF,
                    0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFF00,
                    0x00FF, 0xFFFF, 0x0000, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000,
                    0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFF00, 0x00FF, 0x0000,
                    0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000,
                    0xFF00, 0x00FF, 0xFFFF, 0x0000, 0xFF00, 0x00FF, 0x0000, 0x0000, 0x0000, 0xFFFF,
                    0x0000, 0x0000, 0xFFFF, 0x00FF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x00FF, 0x0000,
                    0x00FF, 0xFFFF, 0x00FF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFF00, 0x00FF, 0x0000, 0x0000, 0xFF00,
                    0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0x0000,
                    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF,
                    0xFFFF, 0x00FF, 0xFF00, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000,
                    0x0000, 0xFFFF, 0x00FF, 0x0000, 0xFF00, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0x0000,
                    0x0000, 0xFF00, 0xFFFF, 0xFFFF, 0x00FF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000,
                    0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
                    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF,
                    0x0000, 0x0000, 0x0000, 0x0000,};
