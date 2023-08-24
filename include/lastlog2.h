/* SPDX-License-Identifier: BSD-2-Clause

  Copyright (c) 2023, Thorsten Kukuk <kukuk@suse.com>

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice,
     this list of conditions and the following disclaimer.

  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#define _PATH_LASTLOG2 "/var/lib/lastlog/lastlog2.db"

#include <stdint.h>

/* Check if database file exists.
   Returns 0 on success, -1 on failure. */
extern int ll2_check_database (const char *lastlog2_path);
/* Write a new entry. Returns 0 on success, -1 on failure. */
extern int ll2_write_entry (const char *lastlog2_path, const char *user,
			    int64_t ll_time, const char *tty,
			    const char *rhost, const char *pam_service,
			    char **error);
extern int ll2_read_all (const char *lastlog2_path,
			 int (*callback)(const char *user, int64_t ll_time,
					 const char *tty, const char *rhost,
					 const char *pam_service),
			 char **error);
extern int ll2_read_entry (const char *lastlog2_path, const char *user,
			   int64_t *ll_time, char **tty, char **rhost,
			   char **pam_service, char **error);
extern int ll2_update_login_time (const char *lastlog2_path,
				  const char *user, int64_t ll_time,
				  char **error);
extern int ll2_remove_entry (const char *lastlog2_path, const char *user,
			     char **error);

extern int ll2_rename_user (const char *lastlog2_path, const char *user,
			    const char *newname, char **error);

extern int ll2_import_lastlog (const char *lastlog2_path, 
		               const char *lastlog_file, char **error);
