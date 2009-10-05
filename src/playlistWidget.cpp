/********************************************************************
 * playlistWidget.cpp
 ********************************************************************
 * This file is part of Bungeni Transcribe
 *
 * Copyright (C) 2009 - UNDESA <www.parliaments.info>
 *
 *
 * Author - Miano Njoka <miano@parliaments.info>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 ***********************************************************************/
 
#include "playlistWidget.hpp"
#include <QDebug>

PlaylistWidget :: PlaylistWidget() : QWidget()
{
    this->setupModelView();
    
    QObject::connect( addToPlaylistButton, SIGNAL(clicked()), this, SLOT(addToPlaylistDialog()));
    QObject::connect( table->verticalHeader(), SIGNAL( sectionDoubleClicked( int ) ), this, SLOT( play( int ) ) );
}

PlaylistWidget :: ~PlaylistWidget()
{
}

void PlaylistWidget :: addToPlaylistDialog()
{
    addToPlaylist = new AddToPlaylistWidget();
    addToPlaylist->show();
    QObject::connect( addToPlaylist, SIGNAL(accepted()), this, SLOT(addItemToPlaylist()));
    
}

void PlaylistWidget :: addItemToPlaylist()
{
    if (addToPlaylist->addExisting())
    {
        QString trsFileLocation = addToPlaylist->getTrsFileLocation();
        //read trs file, locate media file and add it to playlist
    }
    else
    {
        QString sittingName = addToPlaylist->getSittingName();
       // QDateTime startTime = addToPlaylist->getStartTime();
      //  QDateTime endTime = addToPlaylist->getEndTime();
        QString mediaFileLocation = addToPlaylist->getMediaFileLocation();
        model->insertRows(model->rowCount(), 1, QModelIndex());
        /*
        0 - SittingName
        //1 - StartDateTime
       // 2 - EndDateTime
        3 - File
        */
        
	    model->setData(model->index(model->rowCount()-1, 0, QModelIndex()), sittingName);
       // model->setData(model->index(model->rowCount()-1, 1, QModelIndex()), startTime);
      //  model->setData(model->index(model->rowCount()-1, 2, QModelIndex()), endTime);
        model->setData(model->index(model->rowCount()-1, 1, QModelIndex()), mediaFileLocation);
    }
}

void PlaylistWidget :: play(int logicalIndex)
{
    qDebug() << "doubleclick" << logicalIndex;
    current = logicalIndex;
    QString mediaFilePath = model->data(model->index(logicalIndex, 1)).toString();
    emit playMediaFile(mediaFilePath);
}

void PlaylistWidget :: next()
{
    if (current < model->rowCount()-1)
    {
        QString mediaFilePath = model->data(model->index(current+1, 1)).toString();
        table->selectRow(current+1);
        play(current+1);
    }
}

void PlaylistWidget :: prev()
{
    if ( current > 0 )
    {
        QString mediaFilePath = model->data(model->index(current - 1, 1)).toString();
        table->selectRow(current-1);
        play(current-1);
    }
}

void PlaylistWidget :: setupModelView()
{
    model = new QStandardItemModel(0,2,this);
  /*
        0 - SittingName
        1 - StartDateTime
        2 - EndDateTime
        3 - File
        */
    model->setHeaderData(0, Qt::Horizontal, "Sitting Name");
   // model->setHeaderData(1, Qt::Horizontal, "Start Date/Time");
   // model->setHeaderData(2, Qt::Horizontal, "End Date/Time");
    model->setHeaderData(1, Qt::Horizontal, "Media File");
    table = new QTableView(this);
	table->setAlternatingRowColors(true);
    table->setModel(model);
    table->horizontalHeader()->setStretchLastSection ( true );
    table->verticalHeader()->setClickable(true);
    QSizePolicy sizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
    sizePolicy.setHorizontalStretch( 0 );
    sizePolicy.setVerticalStretch( 0 );
    
    addToPlaylistButton = new QPushButton("");
    addToPlaylistButton->setSizePolicy( sizePolicy );
    setupSmallButton( addToPlaylistButton );
    addToPlaylistButton->setIcon(QIcon(":/pixmaps/add.png"));
    
    removeFromPlaylistButton = new QPushButton("");
    removeFromPlaylistButton->setSizePolicy( sizePolicy );
    setupSmallButton( removeFromPlaylistButton );
    removeFromPlaylistButton->setIcon(QIcon(":/pixmaps/remove.png"));
    
    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    
    layout = new QGridLayout();
    layout->addWidget(table,0,0,1,3);
    layout->addWidget(addToPlaylistButton,1,0);
    layout->addWidget(removeFromPlaylistButton,1,1);
    layout->addItem(horizontalSpacer,1,2);
    
    setLayout(layout);
    //table->show();
}