/* 
 * File:   ObjectList.cpp
 * Author: PC-Z510
 * 
 * Created on 9 février 2015, 16:38
 */

#include "ObjectList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ObjectList::ObjectList() {
    count = 0;
//    max_count = DF_MAX_LIST_INIT;
//    p_list = (Object **) malloc(sizeof (Object *));
//    if (p_list == NULL) {
//        printf("Error allocating memory!\n"); //print an error message
//    }
}

//ObjectList::~ObjectList() {
//    count = 0;
//    free(p_list);
//}
//
//ObjectList::ObjectList(const ObjectList& other) {
//    p_list = (Object **) malloc(sizeof (Object *) * other.max_count);
//    memcpy(p_list, other.p_list, sizeof (Object *) * other.max_count);
//    max_count = other.max_count;
//    count = other.count;
//}
//
//ObjectList& ObjectList::operator=(const ObjectList& rhs) {
////    if (rhs != this->p_list) {
//        //if (this->p_list!=NULL){
//        //    free(p_list);
//        //}
//        p_list = (Object **) malloc(sizeof (Object *) * rhs.max_count);
//        memcpy(p_list, rhs.p_list, sizeof (Object *) * rhs.max_count);
//        max_count = rhs.max_count;
//        count = rhs.count;
// //   }
//}

/// Insert object pointer in list.
/// Return 0 if ok, else -1.

int ObjectList::insert(Object *p_o) {
    if (!isFull()){
        list[count]=p_o;
        count++;
        return 1;
    }
    return 0;
    
//    Object **p_temp_item;
//    p_temp_item = (Object **) realloc(p_list, 2 * sizeof (Object *) * max_count);
//    if (p_temp_item != NULL) //realloc was successful
//    {
//        p_list[count] = p_o;
//        p_list = p_temp_item;
//        max_count *= 2;
//        count++;
//        return 0;
//    } else //there was an error
//    {
//        free(p_temp_item);
//        printf("Error allocating memory!\n");
//        return 1;
//    }
}

/// Remove object pointer from list,
/// Return 0 if found, else -1.

int ObjectList::remove(Object *p_o) {
    for (int i = 0; i < count; i++) {
        if (list[i] == p_o) {
            for (int j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            return 1; //found
        }
    }
    return 0; //
    
    
//    for (int i = 0; i < count; i++) {
//        if (p_list[i] == p_o) {
//            for (int j = i; j < count - 1; j++) {
//                p_list[j] = p_list[j + 1];
//            }
//            free(p_list[count]);
//            count--;
//            return 1; //found
//        }
//    }
//    return 0; //not found  
}

/// Clear list (setting count to 0).

void ObjectList::clear() {
    count = 0;
    //free(p_list);
}

/// Return count of number of objects in list.

int ObjectList::getCount() const {
    return count;
}

/// Return true if list is empty, else false.

bool ObjectList::isEmpty() const {
    if (count == 0) {
        return true;
    }
    return false;
}

/// Return true if list is full, else false.

bool ObjectList::isFull() const {
    if (count == DF_MAX_LIST) {
        return true;
    }
    return false;
}



