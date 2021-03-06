/*
    This file is part of libcapwap.

    libcapwap is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libcapwap is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <stdlib.h>
#include <string.h>

#include "capwap.h"
#include "cwmsg.h"

void cwmsg_init(struct cwmsg * cwmsg, uint8_t *buffer, int type, int seqnum, struct radioinfo * radioinfo)
{
	int hlen=8;
	cwmsg->buffer=buffer;
	cwmsg->trnsprthdr=buffer;


	int rmaclen=0;
	cwmsg->flags=0;

	if (radioinfo){
		if (radioinfo->rmac[0]){
			/* we assume the radio mac is already aligned */
			rmaclen=(*radioinfo->rmac);
			memcpy(buffer+8,radioinfo->rmac,rmaclen/8+8);
			cwmsg->flags=CWTH_FLAGS_M;	
		}
	}

	hlen+=rmaclen;
	if (hlen%4)
		hlen = (hlen>>2)*4+4;

	
	cwmsg->ctrlhdr=cwmsg->trnsprthdr+hlen; 
	cwmsg->msgelems=cwmsg->ctrlhdr+8;

	*((uint32_t*)(cwmsg->ctrlhdr))=htonl(type); 

	cwmsg->pos=0;
	cwmsg->hlen=hlen/4;
	if (radioinfo)
		cwmsg->rid=radioinfo->rid;
	else	
		cwmsg->rid=0;
	cwmsg->seqnum=seqnum;
	cwmsg->type=type;
}

