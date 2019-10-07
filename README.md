# ScrewTime 1.1

Author: Peter Keel <seegras@discordia.ch>, 2001-05-11

Fixed on 2019-10-07 to compile on modern Linux. It now
also knows whether its compiled for i386 or x86_64.

A small shared library that allows to change the time a 
program gets when calling gettimeofday() or time().

Usage:
export LD_PRELOAD=./screwtime.so
./testtime

What's the use? Explanation one: To solve Y2K-issues. 
Explanation two: To defeat software license schemes 
based on time. Take it as a proof of concept.

This Program underlies the GNU General Public License (GPL) 3.0. 
See file COPYING for details.

The newest version should also be available on my homepage at 
https://seegras.discordia.ch/
	