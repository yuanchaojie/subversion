/* file.h : interface to file nodes --- private to libsvn_fs
 *
 * ====================================================================
 * Copyright (c) 2000 CollabNet.  All rights reserved.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution.  The terms
 * are also available at http://subversion.tigris.org/license-1.html.
 * If newer versions of this license are posted there, you may use a
 * newer version instead, at your option.
 * ====================================================================
 */

/* ==================================================================== */



#ifndef SVN_LIBSVN_FS_FILE_H
#define SVN_LIBSVN_FS_FILE_H


/* Set *CONTENTS_FN_P and *CONTENTS_BATON_P to a `read'-like function
   which will return the contents of the node ID in FS.  Allocate the
   baton in POOL.

   *CONTENTS_FN_P and *CONTENTS_BATON_P become invalid when FS is
   closed.  */
svn_error_t *svn_fs__file_contents (svn_read_fn_t **contents_fn_p,
				    void **contents_baton_p,
				    svn_fs_t *fs,
				    svn_fs_id_t *id,
				    apr_pool_t *pool);


/* Create a new file node in FS, and set *ID_P to its node revision
   ID.  The file's initial contents are the empty string, and it has
   no properties.  Do any necessary temporary allocation in POOL.  */
svn_error_t *svn_fs__make_file (svn_fs_id_t *id_p,
				svn_fs_t *fs,
				apr_pool_t *pool);


/* Change the contents of the file node ID in FS.  Set *WRITE_FN_P and
   *WRITE_BATON_P to a `write'-like function and a baton; the data
   written using this function and baton become the file's new
   contents.

   The node must have already been cloned as part of some transaction;
   otherwise, this function may corrupt the filesystem.

   Do any necessary temporary allocation in POOL. */
svn_error_t *svn_fs__write_file (svn_write_fn_t **write_fn_p,
				 void **write_baton_p,
				 svn_fs_t *fs,
				 svn_fs_id_t *id,
				 apr_pool_t *pool);


#endif /* SVN_LIBSVN_FS_FILE_H */
