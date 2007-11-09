/***************************************************************************
                          chessxdatabase.h  - chessx native database class 
                             -------------------
   begin                : 15 July 2007
   copyright            : (C) 2007 Rico Zenklusen <rico_z@users.sourceforge.net>
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License version 3 as     *
 *   published by the Free Software Foundation.                            *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License version 3 for more details.                 *
 *                                                                         *
 ***************************************************************************/

#ifndef __CHESSXDATABASE_H__
#define __CHESSXDATABASE_H__

#include <QFile>
#include <QByteArray>
#include <QXmlDefaultHandler>

#include "database.h"
#include "cxdmoves.h"
#include "cxdindex.h"
#include "game.h"
#include "cxdsaxhandler.h"


// Just for tests
#include <iostream>
// ---------------------

/** @ingroup Database
   The ChessXDatabase class provides database access to a native ChessX file
   format.

   @todo
   - handle correcty the m_isModified attribute
*/

// The main file of a ChessXDatabase is an xml file containing meta-information
// about the database as:
// - version string of the database format
// - location of additional files used by the database (files containing the
//   games, headers, keys, ...) 


class ChessXDatabase : public Database
{
public:
  /** Default constructor */
  ChessXDatabase();
  /** Destructor */
  ~ChessXDatabase(); 
  /** Creates a database with the given filename */
  virtual bool create(const QString& filename);
  /** Opens the given database */
  virtual bool open(const QString& filename);
  /** File-based database name */
  virtual QString filename() const;
  /** Closes the database */
  virtual void close();
  /** Returns whether the database is read-only or not */
  virtual bool isReadOnly();
  /** Removes all games from the database, return true if successful */
  virtual bool clear();

  // game retrieval and storage
  /** Loads a game from the given position, returns true if successful */
  virtual bool loadGame(int index, Game& game);
  /** Loads only moves into a game from the given position */
  virtual void loadGameMoves(int index, Game& game);
  /** Saves a game at the given position, returns true if successful.
      As saving of a game at a particular index is in general not an
      efficient operation, it is not supported by this database type
      and always return false.
  */ 
  virtual bool replace(int index, Game& game);
  /** Adds a game to the database */
  virtual bool appendGame(Game& game);
  /** Removes a game from the database */
  virtual bool remove(int index);
  /** Compacts the database */
  virtual void compact();
  /** Returns true if the database has been modified */
  virtual bool isModified();

  static const QString m_currentVersion;

private:

  // Used for parsing xml files (in cxd format) and for holding
  // various data such as used files and version number.
  SaxHandler m_saxhandler;

  CxdMoves m_cxdMoves;
  CxdIndex m_cxdIndex;

  QString m_xmlFilename;
  static const QString m_xmlFilenameExt; // .cxd
  static const QString m_gameFilenameExt; // .cxg
  static const QString m_gameAFilenameExt; // .cxa

  static const QString m_indexFilenameExt; // .cxi
  static const QString m_tagValueFilenameExt; // .cxv
  static const QString m_otherTagsFilenameExt; // .cxt
  static const QString m_otherTagsAFilenameExt; // .cxu

  bool m_isOpen;

  void initialise();
  
  //parsing variables 
  
  // Parses a xcd file
  bool parseCxdFile(const QString& filename);
  bool writeCxdFile(const QString& filename) const;

  // Reads the data for Index from the indexfile. It returns
  // true when successful.
  // UNDER CONSTRUCTION: This function is currently only a dummy
  // function filling m_index in a trivial way.
  bool readIndexData(); 

};


void ricoTest();

#endif