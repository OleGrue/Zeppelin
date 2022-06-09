/************************************************************************************************
 * Copyright (C) 2016
 *
 * Authors:
 * Julian Engelskirchen
 *
 * The "RC-Steuerung"-programm is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************************************/

#include "imagelabel.h"

//constructor
ImageLabel::ImageLabel(QWidget *parent) :
    QWidget(parent)
{}

//paint event handler
void ImageLabel::paintEvent(QPaintEvent *event)
{
    //call super
    QWidget::paintEvent(event);

    //if size is null do nothing
    if (pix.isNull())
    {
        return;
    }

    //paint image with AA
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //scale image while keeping aspect ratio
    QSize pixSize = pix.size();
    pixSize.scale(event->rect().size(), Qt::KeepAspectRatio);

    //transform image to scaled version
    QPixmap scaledPix = pix.scaled(pixSize,
                                   Qt::KeepAspectRatio,
                                   Qt::SmoothTransformation
                                   );

    //draw image
    painter.drawPixmap(QPoint(), scaledPix);
}

//returns the current image
const QPixmap* ImageLabel::pixmap() const
{
    return &pix;
}

//sets the current image
void ImageLabel::setPixmap (const QPixmap &pixmap)
{
    pix = pixmap;
}
