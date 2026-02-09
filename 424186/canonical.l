%{
#include<stdio.h>
 int begin_context =0;
  %}

  %%
  "begin"{
    if begin_context
  } 
