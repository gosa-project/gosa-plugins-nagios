<?php

/*
   This code is part of GOsa (https://gosa.gonicus.de)
   Copyright (C) 2007 Fabian Hickert

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


class setup_step_3 extends setup_step
{
  var $license_found  = false;
  var $License        = "";

  function setup_step_3()
  {
    $this->update_strings();

    if(!file_exists("../setup/license.txt")){
      $this->License = "<font color='red'>License not found. Setup stops here.</font>";
    }else{
      $fp = fopen("../setup/license.txt","r");
      $this->License = "";
      while (!feof($fp)){
        $this->License .= fread($fp, 255);
      }
      $this->license_found = true;
    }
  }


  function update_strings()
  {
    $this->s_title      = _("License");
    $this->s_title_long = _("GNU / GPL-License");
    $this->s_info       = _("GNU / GPL-License");
  }

 
  function execute()
  {
    $smarty = get_smarty();
    $smarty -> assign("License",nl2br($this->License));
    $smarty -> assign("license_found",$this->license_found);
    $this->is_completed = true;
    return($smarty -> fetch (get_template_path("../setup/setup_step3.tpl")));
  }

}

// vim:tabstop=2:expandtab:shiftwidth=2:filetype=php:syntax:ruler:
?>