//
//  AWAlert.cpp
//  CocoaSimulator
//
//  Created by Pierre Molinaro on 28/05/2017.
//  Copyright © 2017 Pierre Molinaro. All rights reserved.
//
//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

#include "AWAlert.h"
#include "AWRectView.h"
#include "AWPushButton.h"
#include "AWLabel.h"
#include "AWContext.h"
#include "AW-settings.h"
#include "AWInvisiblePushButton.h"

static const uint16_t kAlertMargin = 2 ;
static const uint16_t kAlertAdornWidth = 2 ;

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————

void presentAlert (const String & inTitle,
                   AWAction inCancelAction,
                   AWAction inOkAction,
                   const int inOkActionTag) {
  const AWRect screenRect = AWContext::screenRect () ;
  const AWInt width = screenRect.size.width / 2 ;
  const AWInt height = screenRect.size.height / 4 ;
  const AWRect alertRect ((screenRect.size.width - width) / 2, (screenRect.size.height - height) / 2, width, height) ;
  AWView * alert = new AWInvisiblePushButton (screenRect) ;
  AWView * alertSubview = new AWRectView (alertRect, AWColor::white (), AWColor::black(), kAlertMargin, kAlertAdornWidth ) ;
  alert->addSubView (alertSubview) ;
//--- Ok button
  AWPoint p (alertRect.size.width - 80 - 10 - 2 * ( kAlertMargin + kAlertAdornWidth ), 25 + kAlertMargin + kAlertAdornWidth) ;
  AWPushButton * okButton = new AWPushButton (p, 80, "Ok") ;
  okButton->setTag (inOkActionTag) ;
  alertSubview->addSubView (okButton) ;
//--- Cancel button
  p.x = 10 + kAlertMargin + kAlertAdornWidth;
  AWPushButton * cancelButton = new AWPushButton (p, 80, "Annuler") ;
  cancelButton->setAction (inCancelAction) ;
  alertSubview->addSubView (cancelButton) ;
//--- Title
  p.x = 0 ;
  p.y = alertRect.size.height / 2 + 20 ;
  AWView * view = new AWLabel (p, alertRect.size.width, kAWAlignmentCenter, inTitle) ;
  alertSubview->addSubView (view) ;
  AWContext::internalPresentAlert (alert, cancelButton, okButton, inOkAction) ;
}

//——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
