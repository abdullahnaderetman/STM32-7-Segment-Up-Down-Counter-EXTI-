/*
 * 7_SEGMENT.h
 *
 *  Created on: Aug 28, 2025
 *      Author: abdal
 */

#ifndef HAL_7_SEGMENT_7_SEGMENT_H_
#define HAL_7_SEGMENT_7_SEGMENT_H_

#include "../../LIB/STD_TYPES.h"
#define SEGMENT_A 0
#define SEGMENT_B 1
#define SEGMENT_C 2
#define SEGMENT_D 3
#define SEGMENT_E 4
#define SEGMENT_F 5
#define SEGMENT_G 6

void segment_show(u8 number);
void Segment_int(void);
void Segment_Disable(void);

#endif /* HAL_7_SEGMENT_7_SEGMENT_H_ */
