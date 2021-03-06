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


#ifndef __CAPWAP_CISCO_H
#define __CAPWAP_CISCO_H

#define CWVENDOR_CISCO_RAD			3
#define CWVENDOR_CISCO_RAD_SLOT			4
#define CWVENDOR_CISCO_RAD_NAME			5
#define	CWVENDOR_CISCO_MWAR			6
#define CWVENDOR_CISCO_AP_TIMESYNC		151


extern void cwmsg_addelem_vendor_cisco_ap_timesync(struct cwmsg * cwmsg);

#endif
