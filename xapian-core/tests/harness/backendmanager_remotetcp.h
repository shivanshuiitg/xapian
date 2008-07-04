/** @file backendmanager_remotetcp.h
 * @brief BackendManager subclass for remotetcp databases.
 */
/* Copyright (C) 2007 Olly Betts
 * Copyright (C) 2008 Lemur Consulting Ltd
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef XAPIAN_INCLUDED_BACKENDMANAGER_REMOTETCP_H
#define XAPIAN_INCLUDED_BACKENDMANAGER_REMOTETCP_H

#include "backendmanager.h"
#include "backendmanager_remote.h"

#include <string>

/// BackendManager subclass for remotetcp databases.
class BackendManagerRemoteTcp : public BackendManagerRemote {
    /// Don't allow assignment.
    void operator=(const BackendManagerRemoteTcp &);

    /// Don't allow copying.
    BackendManagerRemoteTcp(const BackendManagerRemoteTcp &);

    /// The path of the last writable database used.
    std::string last_wdb_name;

  public:
    BackendManagerRemoteTcp(const std::string & remote_type_);

    /** We have virtual methods and want to be able to delete derived classes
     *  using a pointer to the base class, so we need a virtual destructor.
     */
    virtual ~BackendManagerRemoteTcp();

    /// Return a string representing the current database type.
    std::string get_dbtype() const;

    /// Create a RemoteTcp Xapian::Database object indexing multiple files.
    Xapian::Database get_database(const std::vector<std::string> & files);

    /// Create a RemoteTcp Xapian::Database object indexing a single file.
    Xapian::Database get_database(const std::string & file);

    /// Create a RemoteTcp Xapian::WritableDatabase object indexing a single file.
    Xapian::WritableDatabase get_writable_database(const std::string & name,
						   const std::string & file);

    /// Create a RemoteTcp Xapian::Database with the specified timeout.
    Xapian::Database get_remote_database(const std::vector<std::string> & files,
					 unsigned int timeout);

    /// Create a Database object for the last opened WritableDatabase.
    Xapian::Database get_writable_database_as_database(const std::string & name = "");

    /// Create a WritableDatabase object for the last opened WritableDatabase.
    Xapian::WritableDatabase get_writable_database_again(const std::string & name = "");

    /// Called after each test, to perform any necessary cleanup.
    virtual void posttest();
};

#endif // XAPIAN_INCLUDED_BACKENDMANAGER_REMOTETCP_H
