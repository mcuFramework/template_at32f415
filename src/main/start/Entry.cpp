/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf.h"
#include "core_arterytek_at32f415.h"

//-----------------------------------------------------------------------------------------
#include "start/Entry.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using start::Entry;
using mcuf::lang::Memory;
using mcuf::lang::Pointer;
using mcuf::lang::Thread;

extern void setup(Thread* _this);
extern void loop(Thread* _this);
extern void lowlevel(void);


extern "C" int main(void){
  lowlevel();
  Entry entry = Entry(1024);
  mcuf::lang::System::start(entry);
}

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
Entry::Entry(uint32_t stackSize) : Thread(stackSize){
  return;
}

/**
 *
 */
Entry::~Entry(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */

/**
 *
 */
void Entry::run(void){
  setup(this);
  while(true){
    loop(this);
  }
};

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
