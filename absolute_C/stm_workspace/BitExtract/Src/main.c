
#include<stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*
 * This structure we used to store various fields of the packet in to variables
 * The variable of this structure consumes 4 bytes in the memory
*/

struct Packet
	{
		uint32_t crc			:2;
		uint32_t status			:1;
		uint32_t payload		:12;
		uint32_t bat			:3;
		uint32_t sensor			:3;
		uint32_t longAddr		:8;
		uint32_t shortAddr		:2;
		uint32_t addrMode		:1;
	};



int main(void)
{
	uint32_t packetValue = 0x000;
	struct Packet packet;

	  packet.crc		=	(uint8_t)(packetValue & 0x03);
	  packet.status		=	(uint8_t)((packetValue >> 2)& 0x01);
	  packet.payload	=	(uint8_t)((packetValue >> 3)& 0xFF);
	  packet.bat		=	(uint8_t)((packetValue >> 15)& 0x07);
	  packet.sensor		=	(uint8_t)((packetValue >> 18)& 0x07);
	  packet.longAddr	=	(uint8_t)((packetValue >> 21)& 0x0FF);
	  packet.shortAddr	=	(uint8_t)((packetValue >> 29)& 0x03);
	  packet.addrMode	=	(uint8_t)((packetValue >> 31)& 0x01);

	   printf("crc      :%#x\n",packet.crc);
	   printf("status   :%#x\n",packet.status);
	   printf("payload  :%#x\n",packet.payload);
	   printf("bat      :%#x\n",packet.bat);
	   printf("sensor   :%#x\n",packet.sensor);
	   printf("longAddr :%#x\n",packet.longAddr);
	   printf("shortAddr:%#x\n",packet.shortAddr);
	   printf("addrMode :%#x\n",packet.addrMode);

	   printf("Size of union is %I64u\n",sizeof(packet));



	   while(1){

	   }

		return 0;
}