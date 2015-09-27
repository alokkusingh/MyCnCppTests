/*
 * IPC.cpp
 *
 *  Created on: 11-Sep-2011
 *      Author: Alok
 */

/*
* A very simple server using Shared Memory example to communicate between processes.
*
* The parent will assign the shared memory segment to a random integer, and the child process will
* display what it sees.
*/

//needed for the Shared Memory Functionality
//#include <sys/ipc.h>
#include <sys/shm.h>

//console based IO library
#include <iostream>

//For generating our keys
#include <cstdlib> //needed for the rand function
#include <ctime> //needed to work with time for seeding

#include <sys/sem.h>

using namespace std;

//These are our function declarations
void *get_shared_memory_segment(const int &, const char *); //getting shared memory segments

int main(int argc, char *argv[])
{
     //constants for shared memory sizes
     const int SHM_INT_SIZE = sizeof(int);
     const int MAX_CHILDREN = 7;

     //Message Count
     int *shared_int, *child_count, pid;

     //We do not want any geeky stuff happening with the child processes later on,
     //so set this up so that
     //the parent does not need to wait for the child to terminate
     //signal(SIGCLD, SIG_IGN);
     signal(SIGCHLD, SIG_IGN);

     //seed the random number generator
     srand(time(0));

     //Be verbose, let the console know how large the shared memory segment is set to
     cout << "Size of Shared Memory Segment for ints: " << SHM_INT_SIZE << endl;

     //get our shared memory segments
     shared_int = (int *)get_shared_memory_segment(SHM_INT_SIZE, argv[0]);
     child_count = (int *)get_shared_memory_segment(SHM_INT_SIZE, argv[0]);

     if ((!shared_int) || (!child_count))
     {
          cerr << "Error allocating shared memory!" << endl;
          shared_int = NULL;
          child_count = NULL;
          exit(-1);
     }

     //initialize our counts to 0
     *shared_int = 0;
     *child_count = 0;

     //Repeat indefinitly
     while (1) {
      if (*child_count < MAX_CHILDREN)
      {
          *child_count = *child_count + 1;
          cout << "--------------------------------" << endl;
          cout << "Number of Children after fork: " << *child_count << endl;
          cout << "--------------------------------" << endl;

          pid = fork();

           if (pid < 0)
           {
               cerr << "Error on fork!" << endl;
                shared_int = NULL;
                child_count = NULL;
                exit(-1);
           }
      }
      else
      {
           cout << "--------------------------------" << endl;
           cout << "Max children reached. I am not spawning anymore." << endl;
           cout << "--------------------------------" << endl;
      }
      if (pid == 0)  {
          //Inside of child process

          for (int x = 0; x < 20; x++)
          {
          cout << "I am a child " << getpid() << " and I see: " << *shared_int << endl;
          sleep(3);
          }

          *child_count = *child_count - 1;
          cout << "--------------------------------" << endl;
          cout << "I am dieing... Number of Childred: " << *child_count << endl;
          cout << "--------------------------------" << endl;
          //Exit child process
          exit(0);
         }
         else
      {
          //Inside of parent process
          *shared_int = rand();
          cout << "I am the parent " << getpid() << " and I just set the shared memory segment to: " << *shared_int << endl;
          sleep(5);
      }
     }

     return 0; /* we never get here due to CTRL-C the parent */
}


///////////////////////////////////////////////////////////////////////////////////////
//This will allocate the Shared Memory Segment and return a pointer to that segment
void *get_shared_memory_segment(const int &size, const char *filename)
{
     //Variables for our Shared Memory Segment
     key_t key;
     int shmid;
     int err = 0;

     //This is our local pointer to the shared memory segment
     void *temp_shm_pointer;

     //Create our shared memory key for client connections
     if ((key = ftok(filename, 1 + (rand() % 255) )) == -1)
     //if ((key = ftok(filename, 'b')) == -1)
                //error("Failed to FTOK");
          err = 1;
     cout<<"Alok: key: "<<key<<endl;
     //Connect to the shared memory segment and get the shared memory ID

     //The ftok function creates a sort of identifier to be used with the
     //System V IPC functions (semget, shmget, msgget).

     //The reason for the system scope is that you want two or more independent processes to have access to the same IPC resources. So if you have two programs, both of which execute key = ftok("/home/beej/somefile", 'b');, both will get the same token and can therefor access the same resources (semaphores, shared memory, message queues). That's the whole point of Inter Process Communication.

     //if ((shmid = semget(key, 10, 0666 | IPC_CREAT)) == -1)
     if ((shmid = shmget(key, size, IPC_CREAT | 0600)) == -1)
     //error("shmget attempt failed");
     err = 1;
     cout<<"Alok: shmid: "<<shmid<<endl;
     // point the clients to the segment
     temp_shm_pointer = (void *)shmat(shmid, 0, 0);
     if (temp_shm_pointer == (void *)(-1))
        //error("shmat failure");
     err = 1;

     //Return the pointer
     if (!err)
          return temp_shm_pointer;
     else
     return 0;
}
