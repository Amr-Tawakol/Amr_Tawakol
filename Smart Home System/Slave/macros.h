#define SET_BIT(reg,bit_num)       reg = reg | (1<<bit_num)
#define CLR_BIT(reg,bit_num)       reg=reg & (~(1<<bit_num))
#define TOGGLE_BIT(reg,bit_num)       reg = reg ^ ((1<<bit_num))
#define GET_BIT(reg,bit_num)        (reg >> bit_num)& 0x01
