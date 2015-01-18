/* 
 * File:   ssql_tpl.h
 * Author: bayucandra@gmail.com
 *
 * Created on January 17, 2015, 9:28 PM
 */

#ifndef SSQL_TPL_H
#define	SSQL_TPL_H

#include <mysql++.h>
#include "ssqls.h"

sql_create_4(bkelas,
        1, 4,
        mysqlpp::sql_int, idbkelas,
        mysqlpp::sql_char , kelas,
        mysqlpp::sql_char, keterangan,
        mysqlpp::sql_int, tunjangan_perbulan
);

#endif	/* SSQL_TPL_H */

