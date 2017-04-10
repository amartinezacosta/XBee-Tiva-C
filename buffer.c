#include "buffer.h"

void Buffer_Init(Buffer *b, uint8_t *buffer, uint32_t buffer_size){
    b->Buffer = buffer;
    b->Buffer_ReadIndex = 0;
    b->Buffer_WriteIndex = 0;
    b->Buffer_Size = buffer_size;
}

int32_t Buffer_Write(Buffer *b, uint8_t *data, uint32_t size){
    int32_t i;
    for(i = 0; i < size; i++){
        /*write data only if buffer is not full*/
        if(!Buffer_Full(b)){
            b->Buffer[b->Buffer_WriteIndex] = data[i];
            b->Buffer_WriteIndex = (b->Buffer_WriteIndex + 1) % b->Buffer_Size;
        }
        /*break the loop if the buffer is full*/
        else{
            break;
        }
    }

    return i;
}

int32_t Buffer_Read(Buffer *b, uint8_t *data, uint32_t size){
    int32_t i;
    for(i = 0; i < size; i++){
        /*read data only if buffer is not empty*/
        if(!Buffer_Empty(b)){
            data[i] = b->Buffer[b->Buffer_ReadIndex];
            b->Buffer_ReadIndex = (b->Buffer_ReadIndex + 1) % b->Buffer_Size;
        }
        /*break the loop if the buffer is full*/
        else{
            break;
        }
    }

    return i;
}


uint32_t Buffer_Used(Buffer *b){
    return b->Buffer_WriteIndex - b->Buffer_ReadIndex;
}

bool Buffer_Full(Buffer *b){
    if(b->Buffer_WriteIndex + 1 == b->Buffer_ReadIndex){
        return true;
    }
    else{
        return false;
    }
}

bool Buffer_Empty(Buffer *b){
    if(b->Buffer_ReadIndex == b->Buffer_WriteIndex){
        return true;
    }
    else{
        return false;
    }
}

