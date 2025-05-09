//***************************************************************************
// Copyright 2007-2025 Universidade do Porto - Faculdade de Engenharia      *
// Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  *
//***************************************************************************
// This file is part of DUNE: Unified Navigation Environment.               *
//                                                                          *
// Commercial Licence Usage                                                 *
// Licencees holding valid commercial DUNE licences may use this file in    *
// accordance with the commercial licence agreement provided with the       *
// Software or, alternatively, in accordance with the terms contained in a  *
// written agreement between you and Faculdade de Engenharia da             *
// Universidade do Porto. For licensing terms, conditions, and further      *
// information contact lsts@fe.up.pt.                                       *
//                                                                          *
// Modified European Union Public Licence - EUPL v.1.1 Usage                *
// Alternatively, this file may be used under the terms of the Modified     *
// EUPL, Version 1.1 only (the "Licence"), appearing in the file LICENCE.md *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// https://github.com/LSTS/dune/blob/master/LICENCE.md and                  *
// http://ec.europa.eu/idabc/eupl.html.                                     *
//***************************************************************************
// Author: Ricardo Martins                                                  *
// Edit: Pedro Gonçalves                                                    *
//***************************************************************************

var HIDE_PREFIX = "Private (";

function Power(root_id) {
  this.serial = 0;

  this.create('Power', root_id);

  // Subpanel.
  this.m_sbase = document.createElement('div');
  this.m_sbase.width = '100%';

  // Save button.
  var btn = document.createElement('button');
  btn.onclick = function (event) { submitPowerForm('all', 'save', 0, event); };
  btn.textContent = 'Save State';
  //add courser style
  btn.style.cursor = "alias";

  this.m_base.appendChild(this.m_sbase);
  this.m_base.appendChild(btn);
};

Power.prototype = new BasicSection;

Power.prototype.updateEntry = function (msg) {
  if (msg.name.slice(0, HIDE_PREFIX.length) == HIDE_PREFIX)
    return;

  for (var i = 0; i < this.m_sbase.childNodes.length; i++) {
    var child = this.m_sbase.childNodes[i];
    var name = child.firstChild.firstChild.firstChild.data;

    if (name == msg.name) {
      this.updateValue(child, msg);
      return;
    }
    else if (msg.name < name) {
      var ne = this.createEntry(msg);
      this.m_sbase.insertBefore(ne, child);
      return;
    }
  }

  var ne = this.createEntry(msg);
  this.m_sbase.appendChild(ne);
};

Power.prototype.updateValue = function (root, msg) {
  var base = root.childNodes[1].firstChild.firstChild;
  if (msg.state == 0) {
    // set image a of childNodes[1]
    base.childNodes[1].src = 'images/icons/system-off.png';
    base.childNodes[2].disabled = false;
    base.childNodes[2].classList.add('active');
    base.childNodes[3].disabled = true;
    base.childNodes[3].classList.remove('active');
  }
  else {
    base.childNodes[1].src = 'images/icons/system-on.png';
    base.childNodes[2].disabled = true;
    base.childNodes[2].classList.remove('active');
    base.childNodes[3].disabled = false;
    base.childNodes[3].classList.add('active');
  }
};

Power.prototype.createEntry = function (msg) {
  this.serial = this.serial + 1;

  // Header.
  var th = document.createElement('th');
  th.colSpan = 2;
  th.appendChild(document.createTextNode(msg.name));
  var tr = document.createElement('tr');
  tr.appendChild(th);

  // Controls.
  var ctr = document.createElement('tr');

  var form = document.createElement('form');
  form.id = 'PowerChannelForm' + this.serial;
  var btd = document.createElement('td');
  btd.appendChild(form);

  var name = document.createElement('input');
  name.type = 'hidden';
  name.value = msg.name;
  form.appendChild(name);

  this.appendImage(form, msg.name, 'status', 'Status');
  this.appendButton(form, msg.name, 'on', 'Turn On');
  this.appendButton(form, msg.name, 'off', 'Turn Off');
  this.appendInput(form, form.id, 'Hours', 'hour(s)');
  this.appendInput(form, form.id, 'Minutes', 'minute(s)');
  this.appendInput(form, form.id, 'Seconds', 'second(s)');
  this.appendButton(form, msg.name, 'sched_on', 'Schedule On');
  this.appendButton(form, msg.name, 'sched_off', 'Schedule Off');
  this.appendButton(form, msg.name, 'reset', 'Reset Schedules');

  ctr.appendChild(btd);

  // Table.
  var tbl = document.createElement('table');
  tbl.appendChild(tr);
  tbl.appendChild(ctr);

  this.updateValue(tbl, msg);

  return tbl;
};

Power.prototype.appendImage = function (root, channel, op, label) {
  var img = document.createElement('img');
  img.src = 'images/icons/unknown.png';
  img.alt = label;
  img.style.width = 'auto';
  img.style.height = '42px';
  img.style.marginTop = '7px';
  img.style.marginRight = '20px';
  root.appendChild(img);
}

Power.prototype.appendButton = function (root, channel, op, label) {
  var btn = document.createElement('button');
  btn.onclick = function (event) { submitPowerForm(channel, op, root.id, event); };
  btn.textContent = label;
  btn.setAttribute('data-op', op);
  root.appendChild(btn);
};

Power.prototype.appendInput = function (root, form_id, id, label) {
  var einput = document.createElement('input');
  einput.id = form_id + id;
  einput.type = 'text';
  einput.value = '0';
  einput.size = 5;
  root.appendChild(einput);

  var etext = document.createTextNode(label);
  root.appendChild(etext);
};

Power.prototype.update = function () {
  for (var i in g_data.dune_messages) {
    var msg = g_data.dune_messages[i];
    if (msg.abbrev != 'PowerChannelState')
      continue;

    this.updateEntry(msg);
  }
};

function handlePower(text) {
}

function submitPowerForm(channel, op, id, event) {
  if (event) {
    event.preventDefault();
  }

  var url = 'dune/power/channel/' + op + '/' + channel;

  if (op == 'sched_on' || op == 'sched_off') {
    var h = document.getElementById(id + 'Hours').value;
    var m = document.getElementById(id + 'Minutes').value;
    var s = document.getElementById(id + 'Seconds').value;
    url += '/' + h + '/' + m + '/' + s;
  }

  var activeBtn = event.target;
  activeBtn.classList.add('loading');
  setTimeout(function () {
    activeBtn.classList.remove('loading');
  }, 500);

  var btnOn = document.querySelector(`#${id} button[data-op="on"]`);
  var btnOff = document.querySelector(`#${id} button[data-op="off"]`);
  if (op === 'on') {
    btnOn.classList.remove('active');
    btnOn.disabled = true;
    btnOff.classList.remove('active');
    btnOff.disabled = true;
  } else if (op === 'off') {
    btnOn.classList.remove('active');
    btnOn.disabled = true;
    btnOff.classList.remove('active');
    btnOff.disabled = true;
  }

  //print url
  console.log(url);

  var options = Array();
  options.timeout = 10000;
  options.timeoutHandler = null;
  options.errorHandler = null;

  HTTP.get(url, function (response) {
    handlePower(response);
  }, options);
}
