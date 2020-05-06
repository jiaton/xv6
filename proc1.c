//
// Created by Chao Shang on 2020/4/30.
//
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]){
    int i,j;
    int priority = 3;

    set_priority(priority);
    printf(1, "proc1: process %d with priority %d start\n", getpid(), priority);
    for(i = 0;i < 8000;i++){
        asm("nop");
        for(j = 0;j < 8000;j++)
            asm("nop");
//        for(k=0; k < 43000; k++){
//            asm("nop");
//        }
    }
    printf(1,"process %d with priority %d exit\n",getpid(),priority);
    exit_status(1);
}

