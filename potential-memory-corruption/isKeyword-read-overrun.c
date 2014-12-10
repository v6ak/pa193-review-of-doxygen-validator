/**
 * @author      Archit Agarwal
 * @file        input.c
 * @version     1.0
 * @since       15 Nov 2014
 *
 * This file contains the definitions and API functions required to use Hardware Security Module
 * <p>
 * HSM allows to import two master keys and Personal Identification Number Initialization

 * </p>
 * @see
 *
 *
 */

#include <stdio.h>

/**
 * @brief delete_keys
 *
 *  Deleting Keys
 * <p>
 * This api is used for loading keys
 * </p>
 *
 * @param  type_user Type of user (Only Admin user can perform this operation)
 * @param  pin
 * @param  session_id
 * This file will end with at sign without end of line, so the at sign will be the last token. The program will try to do some overrun.
 * @