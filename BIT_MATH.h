#ifndef LBIT_MATH_H_
#define LBIT_MATH_H_

/*Operations on BITS*/
#define SET_BIT(REG,BIT_NUM)        (REG) |= (1<<(BIT_NUM))
#define CLR_BIT(REG,BIT_NUM)        (REG) &=~(1<<(BIT_NUM))
#define TOG_BIT(REG,BIT_NUM)        (REG) ^= (1<<(BIT_NUM))
#define GET_BIT(REG,BIT_NUM)        (((REG)>>(BIT_NUM)) &1)
/*Operations On PORT[1 Byte]*/
#define SET_PORT(REG)               (REG) |= 0xFF
#define CLR_PORT(REG)               (REG) &= 0x00
#define TOG_PORT(REG)               (REG) ^= 0xFF
#define GET_PORT(REG)               (REG)


#endif /* LBIT_MATH_H_ */
