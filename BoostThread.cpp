/*
 * BoostThread.cpp
 *
 *  Created on: 18-Sep-2011
 *      Author: Alok
 */

#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>

using namespace std;
using boost::mutex;
using boost::thread;

int threadedAPI1( );
int threadedAPI2( );
int threadedAPI3( );
int threadedAPI4( );

int threadedAPI1( ) {
        cout << "Thread0" << endl;
}


int threadedAPI2( ) {
        cout << "Thread1" << endl;
}

int threadedAPI3( ) {
        cout << "Thread2" << endl;
}

int threadedAPI4( ) {
        cout << "Thread3" << endl;
}

int main(int argc, char* argv[]) {

        boost::threadpool::thread_pool<> threads(4);
        // start a new thread that calls the "threadLockedAPI" function
        threads.schedule(boost::bind(&threadedAPI1,0));
        threads.schedule(boost::bind(&threadedAPI2,1));
        threads.schedule(boost::bind(&threadedAPI3,2));
        threads.schedule(boost::bind(&threadedAPI4,3));
        // wait for the thread to finish
        threads.wait();

        return 0;
}
