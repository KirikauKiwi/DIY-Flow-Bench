
#include "public_html.h"



/***********************************************************
 * @brief Header
 *
 *
 *
 ***/
String PublicHTML::header() {

    String header PROGMEM = R"HEADER('
<!DOCTYPE HTML>
<html lang="en">
	<HEAD>
      <title>DIY Flow Bench</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <link rel="stylesheet" type="text/css" href="style.css">
      <link rel="stylesheet" type="text/javascript" href="cookies.js">
	</HEAD>
	<BODY>

    <input type="hidden" id="ACTIVE_ORIFICE" value=""></input>
    <input type="hidden" id="BENCH_TYPE" value=""></input>

    <!-- Main page code -->
    <div class="headerbar">
        <h1><a href="/" id="PAGE_TITLE" alt="DIY Flow Bench">DIY Flow Bench</a></h1>
    </div>

    <!-- Navbar-->
    <button class="tablink" onclick="location.href = '/';" id="load-dashboard-button">~LANG_GUI_DASHBOARD~</button>
    <button class="tablink" onclick="location.href = 'data';" id="load-datalog-button">~LANG_GUI_DATA~</button>
    <button class="tablink" onclick="location.href = 'settings';" id="load-config-button">~LANG_GUI_CONFIG~</button>
    )HEADER";

return header;
}





/***********************************************************
 * @brief Footer
 *
 *
 *
 ***/
String PublicHTML::footer() {

    String footer PROGMEM = R"FOOTER(
  <script type="text/javascript" src="main.js"></script>

  <!-- Footer -->
  <div id="footer"><a href="https://diyflowbench.com" target="new">DIYFlowBench.com</a></div>
  </BODY>
</HTML>
    )FOOTER";

return footer;
}









/***********************************************************
 * @brief Index
 *
 *
 *
 ***/
String PublicHTML::index() {

    const char index_html[] PROGMEM = R"HTML('
<!DOCTYPE HTML>
<html lang="en">
	<HEAD>
      <title>DIY Flow Bench</title>
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <link rel="stylesheet" type="text/css" href="style.css">
      <link rel="stylesheet" type="text/javascript" href="cookies.js">
	</HEAD>
	<BODY>

  <input type="hidden" id="ACTIVE_ORIFICE" value=""></input>
  <input type="hidden" id="BENCH_TYPE" value=""></input>

  <!-- Main page code -->
  <div class="headerbar">
      <h1><a href="/" id="PAGE_TITLE" alt="DIY Flow Bench">DIY Flow Bench</a></h1>
  </div>

  <!-- Navbar-->
  <button class="tablink" onclick="location.href = '/';" id="load-dashboard-button">~LANG_GUI_DASHBOARD~</button>
  <button class="tablink" onclick="location.href = 'data';" id="load-datalog-button">~LANG_GUI_DATA~</button>
  <button class="tablink" onclick="location.href = 'settings';" id="load-config-button">~LANG_GUI_CONFIG~</button>


  <!-- Save Data Modal -->
  <div id="captureLiftDataModal" class="modal">
    <div class="modal-content">
      <span class="closeCaptureLiftDataModalButton">&times;</span>
      <h3>~LANG_GUI_SELECT_LIFT_VAL_BEFORE_CAPTURE~</h3>
      <hr>
      <div class="align-center" >
        <form method="POST" class="lift_data_form" name="lift_data_form" enctype="multipart/form-data">
          <label>~LANG_GUI_LIFT_VAL~</label>
          <br>
            <div class="switch-field">
              <input type="radio" id="lift-one" name="lift-data" value="1"/>
              <label for="lift-one">~lift1~</label>
              <input type="radio" id="lift-two" name="lift-data" value="2" />
              <label for="lift-two">~lift2~</label>
              <input type="radio" id="lift-three" name="lift-data" value="3"/>
              <label for="lift-three">~lift3~</label>
              <input type="radio" id="lift-four" name="lift-data" value="4" />
              <label for="lift-four">~lift4~</label>
              <input type="radio" id="lift-five" name="lift-data" value="5" />
              <label for="lift-five">~lift5~</label>
              <input type="radio" id="lift-six" name="lift-data" value="6" />
              <label for="lift-six">~lift6~</label>
              <input type="radio" id="lift-seven" name="lift-data" value="7" />
              <label for="lift-seven">~lift7~</label>
              <input type="radio" id="lift-eight" name="lift-data" value="8" />
              <label for="lift-eight">~lift8~</label>
              <input type="radio" id="lift-nine" name="lift-data" value="9" />
              <label for="lift-nine">~lift9~</label>
              <input type="radio" id="lift-ten" name="lift-data" value="10" />
              <label for="lift-ten">~lift10~</label>
              <input type="radio" id="lift-eleven" name="lift-data" value="11" />
              <label for="lift-eleven">~lift11~</label>
              <input type="radio" id="lift-twelve" name="lift-data" value="12" />
              <label for="lift-twelve">~lift12~</label>
            </div>
          <input class="button submit-button" type="button" id="capture-lift-data-button" value="~LANG_GUI_LIFT_CAPTURE~"/>
        </form>
      </div>
      <div class="clear-both">&nbsp;</div>
    </div>        
  </div>

  <!--Flow Target modal-->
  <div id="flowTargetModal" class="modal">
    <div class="modal-content flowTargetModal">
      <span class="closeFlowTargetModalButton">&times;</span>
      <div class="align-center">
        <form method="POST" action="/api/saveflowtarget" enctype="multipart/form-data">
          <label>~LANG_GUI_USER_FLOW_TARGET_VAL~</label>
            <input id="flowTargetValInput" type="text" name="USER_OFFSET" value="~USER_OFFSET~"/>
            <input class="button submit-button" type="submit" value="~LANG_GUI_USER_FLOW_TARGET_SAVE~"/>
          </form>
      </div>
    </div>        
  </div>

  <!--Calibration modal-->
  <div id="calibrationModal" class="modal">
    <div class="modal-content calibrationModal">
      <span class="closeCalibrationModalButton">&times;</span>
      <div class="align-center">
        <button id="calibrate-button" class="button">~LANG_GUI_CAL_FLOW_OFFSET~</button>
        <button id="leak-cal-button" class="button">~LANG_GUI_CAL_LEAK_TEST~</button>
      </div>
    </div>        
  </div>

  <!-- Load Data Modal -->
  <div id="loadGraphDataModal" class="modal">
    <div class="modal-content">
      <span class="closeLoadGraphDataModalButton">&times;</span>
      <h3>~LANG_GUI_LOAD_LIFT_PROFILE~</h3>
      <hr>
      <br>
      <div class="float-right">
        <form method="POST" action="/api/viewdata" enctype="multipart/form-data">
          <input class="button file-submit-button" type="submit" value="~LANG_GUI_LOAD_LIFT_PROFILE_LOAD~"/>
        </form>
      </div>
      <div class="clear-both">&nbsp;</div>
    </div>        
  </div>

  <!-- Save Data Modal -->
  <div id="saveGraphDataModal" class="modal">
    <div class="modal-content">
      <span class="closeSaveGraphDataModalButton">&times;</span>
      <h3>~LANG_GUI_SAVE_LIFT_DATA~</h3>
      <hr>
      <br>
      <div class="float-right">
        <form method="POST" action="/api/savedata" enctype="multipart/form-data">
          <label class="config-label">~LANG_GUI_SAVE_GRAPH_FILENAME~:</label>&nbsp;<input type="text" value="~FileName~">
          <input class="button file-submit-button" type="submit" value="Load"/>
        </form>
      </div>
      <div class="clear-both">&nbsp;</div>
    </div>        
  </div>

  <div id="tabcontainer">
  <!-- Main Tab-->
  <div id="dashboard" class="tabcontent tabcontentMain">        
    <div class="content">
      <div class="tile-grid">
        <div class="tile tile-pref" id="tile-pref">
          <p class="tile-title" id="tile-pref-title">~LANG_GUI_PREF~</p>
          <p><span class="tile-value" id="PREF">&nbsp;</span></p>
          <p class="units">inH2O</p>
        </div>
        <div class="tile tile-pdiff" id="tile-pdiff">
          <p class="tile-title" id="tile-pdiff-title">~LANG_GUI_PDIFF~</p>
          <p><span class="differential-tile-value" id="PDIFF">&nbsp;</span></p>
          <p class="units">inH2O</p>
        </div>
        <div class="tile tile-flow" id="flow-tile">
          <p class="tile-title" id="flow-tile-title">~LANG_GUI_FLOW~</p>
          <p><span class="tile-value" id="FLOW">&nbsp;</span></p>
          <p class="units">ACFM</p>
        </div>
        <div class="tile tile-aflow" id="aflow-tile">
          <p class="tile-title" id="aflow-tile-title">~LANG_GUI_AFLOW~</p>
          <p><span class="tile-value" id="AFLOW">&nbsp;</span></p>
          <p class="units">~AFLOW_UNITS~&nbsp;&commat;&nbsp;<span id="PADJUST">28</span>&nbsp;inH2O</p>
        </div>
        <div class="tile tile-sflow" id="sflow-tile">
          <p class="tile-title" id="sflow-tile-title">~LANG_GUI_SFLOW~</p>
          <p><span class="tile-value" id="SFLOW">&nbsp;</span></p>
          <p class="units">SCFM:&nbsp;<span id="STD_REF">~STD_REF~</span></p>
        </div>
        <div class="tile tile-flow" id="maf-tile">
          <p class="tile-title" id="maf-tile-title">~LANG_GUI_MFLOW~</p>
          <p><span class="tile-value" id="MFLOW">&nbsp;</span></p>
          <p class="units">KGH</p>
        </div>
        <div class="tile tile-pitot" id="tile-pitot">
          <p class="tile-title" id="tile-pitot-title">~LANG_GUI_PITOT~</p>
          <p><span class="pitot-tile-value" id="PITOT">&nbsp;</span></p>
          <p class="units">m/sec &Delta; <span id="PITOT_DELTA">~PITOT_DELTA~</span>&nbsp;inH2O</p>
        </div>
        <div class="tile tile-swirl" id="tile-swirl">
          <p class="tile-title" id="tile-swirl-title">~LANG_GUI_SWIRL~</p>
          <p><span class="tile-value" id="SWIRL">&nbsp;</span></p>
          <p class="units">rpm</p>
        </div>
        <div class="tile tile-fdiff" id="tile-fdiff">
          <p class="tile-title"  id="tile-fdiff-title">~LANG_GUI_FLOW_DIFF~</p>
          <p><span class="tile-value flowTargetVal" id="FDIFF">&nbsp;</span></p>
          <p class="units"><span id="FDIFFTYPEDESC">~FDIFFTYPEDESC~</span></p>
        </div>
        <div class="tile tile-temp" id="tile-temp">
          <p class="tile-title" id="tile-temp-title">~LANG_GUI_TEMP~</p>
          <p><span class="tile-value" id="TEMP">&nbsp;</span></p>
          <p class="units">~TEMP_UNIT~</p>
        </div>
        <div class="tile tile-baro" id="tile-baro">
          <p class="tile-title" id="tile-baro-title">~LANG_GUI_BARO~</p>
          <p><span class="tile-value" id="BARO">&nbsp;</span></p>
          <p class="units">millibar (hPa)</p>
        </div>
        <div class="tile tile-relh" id="tile-relh">
          <p class="tile-title"id="tile-relh-title">~LANG_GUI_HUMIDITY~</p>
          <p><span class="tile-value" id="RELH">&nbsp;</span></p>
          <p class="units">&percnt;RelH</p>
        </div>
      </div>  
    </div>          
    <div class="align-center">
      <div class="status_message"><span id="STATUS_MESSAGE">~STATUS_MESSAGE~</span></div>                        
      <div class="hidden_div">
        <br>Ref Pressure mV: <span id="PREF_MV">&nbsp;</span>
        <br>MAF mV: <span id="MAF_MV">&nbsp;</span>
        <br>Pitot mV: <span id="PITOT_MV">&nbsp;</span>
      </div>   
      
      <form method="POST" id="orificeRadio" style="display: none;">
        <div class="switch-field">
          <input type="radio" id="orifice1" name="radioOrifice" value="1" ~ORIFICE1_CHECKED~ onchange="orificeChange(this);"/>
          <label for="orifice1">1</label>
          <input type="radio" id="orifice2" name="radioOrifice" value="2" ~ORIFICE2_CHECKED~ onchange="orificeChange(this);"/>
          <label for="orifice2">2</label>
          <input type="radio" id="orifice3" name="radioOrifice" value="3" ~ORIFICE3_CHECKED~ onchange="orificeChange(this);"/>
          <label for="orifice3">3</label>
          <input type="radio" id="orifice4" name="radioOrifice" value="4" ~ORIFICE4_CHECKED~ onchange="orificeChange(this);"/>
          <label for="orifice4">4</label>
          <input type="radio" id="orifice5" name="radioOrifice" value="5" ~ORIFICE5_CHECKED~ onchange="orificeChange(this);"/>
          <label for="orifice5">5</label>
          <input type="radio" id="orifice6" name="radioOrifice" value="6" ~ORIFICE6_CHECKED~ onchange="orificeChange(this);"/>
          <label for="orifice6">6</label>
        </div>
        <div id="orifice-data">Calibrated Flow Rate: <span id="ORIFICE_MAX_FLOW">~ORIFICE_MAX_FLOW~</span>cfm @ <span id="ORIFICE_CALIBRATED_DEPRESSION">~ORIFICE_CALIBRATED_DEPRESSION~</span> inH2O"</div>
      </form>
        
      <button id="on-button" class="control-button">~LANG_GUI_START~</button>
      <button id="off-button" class="control-button">~LANG_GUI_STOP~</button>
      <button id="clear-message-button" class="control-button">~LANG_GUI_CLEAR_ALARM~</button>
      <br>
      <button id="show-capture-modal-button" class="control-button">~LANG_GUI_CAPTURE~</button>

    </div>     
  </div>

  <script type="text/javascript" src="index.js"></script>

  <script type="text/javascript" src="main.js"></script>

  <!-- Footer -->
  <div id="footer"><a href="https://diyflowbench.com" target="new">DIYFlowBench.com</a></div>
  </BODY>
</HTML>

)HTML";

return  index_html;
}








/***********************************************************
 * @brief Data
 *
 *
 *
 ***/
String PublicHTML::data() {

    String data PROGMEM = R"DATA('

    <!-- Datalog tab -->
    <div id="datalog" class="tabcontent tabcontentData">

        <!-- lift graph -->
        <!-- NOTE: Inline styling is required for SVG Download-->
        <div class="graph-container">        
          <svg class="graph" version="1.1" xmlns:xlink="http://www.w3.org/1999/xlink" xmlns="http://www.w3.org/2000/svg" id="dataGraph" style="background-color: #fff; padding-top: 100px;">
          
            <!--Grid-->
            <g class="grid x-grid" id="xGrid" style="stroke: grey; stroke-dasharray: 1 2; stroke-width: 1;">
              <line x1="100" x2="100" y1="0" y2="510"></line>
              <line x1="150" x2="150" y1="0" y2="510"></line>
              <line x1="200" x2="200" y1="0" y2="510"></line>
              <line x1="250" x2="250" y1="0" y2="510"></line>
              <line x1="300" x2="300" y1="0" y2="510"></line>
              <line x1="350" x2="350" y1="0" y2="510"></line>
              <line x1="400" x2="400" y1="0" y2="510"></line>
              <line x1="450" x2="450" y1="0" y2="510"></line>
              <line x1="500" x2="500" y1="0" y2="510"></line>
              <line x1="550" x2="550" y1="0" y2="510"></line>
              <line x1="600" x2="600" y1="0" y2="510"></line>
              <line x1="650" x2="650" y1="0" y2="510"></line>
              <line x1="700" x2="700" y1="0" y2="510"></line>
            </g>

            <g class="grid y-grid" id="yGrid" style="stroke: grey; stroke-dasharray: 1 2; stroke-width: 1;">
              <line x1="90" x2="700" y1="0" y2="0"></line>
              <line x1="90" x2="700" y1="50" y2="50"></line>
              <line x1="90" x2="700" y1="100" y2="100"></line>
              <line x1="90" x2="700" y1="150" y2="150"></line>
              <line x1="90" x2="700" y1="200" y2="200"></line>
              <line x1="90" x2="700" y1="250" y2="250"></line>
              <line x1="90" x2="700" y1="300" y2="300"></line>
              <line x1="90" x2="700" y1="350" y2="350"></line>
              <line x1="90" x2="700" y1="400" y2="400"></line>
              <line x1="90" x2="700" y1="450" y2="450"></line>
              <line x1="90" x2="700" y1="500" y2="500"></line>
            </g>

            <!--Grid Labels-->
            <g class="labels x-labels">
              <text x="100" y="550">Lift:</text>
              <text x="150" y="550">~lift1~</text>
              <text x="200" y="550">~lift2~</text>
              <text x="250" y="550">~lift3~</text>
              <text x="300" y="550">~lift4~</text>
              <text x="350" y="550">~lift5~</text>
              <text x="400" y="550">~lift6~</text>
              <text x="450" y="550">~lift7~</text>
              <text x="500" y="550">~lift8~</text>
              <text x="550" y="550">~lift9~</text>
              <text x="600" y="550">~lift10~</text>
              <text x="650" y="550">~lift11~</text>
              <text x="700" y="550">~lift12~</text>
          </g>
          
          <g class="labels y-labels">
            <text x="80" y="10">~flow10~</text>
            <text x="80" y="60">~flow9~</text>
            <text x="80" y="110">~flow8~</text>
            <text x="80" y="160">~flow7~</text>
            <text x="80" y="210">~flow6~</text>
            <text x="80" y="260">~flow5~</text>
            <text x="80" y="310">~flow4~</text>
            <text x="80" y="360">~flow3~</text>
            <text x="80" y="410">~flow2~</text>
            <text x="80" y="460">~flow1~</text>
            <text x="80" y="510">Flow (cfm)</text>
          </g>

            <!--Graph Key-->
            <g class="labels key-labels">
              <!--
              <text x="625" y="25" id="default-key-text">Current Data</text>
              <line x1="550" y1="20" x2="620" y2="20"  id="default-key" style="stroke:#000;stroke-width:1;stroke-dasharray:4,1;opacity:0.5;" /> 
              
              <line x1="550" y1="35" x2="620" y2="35"  style="stroke:#f50808;stroke-width:2;opacity:0.5;" /> 
              <text x="625" y="40">Exhaust</text>
              -->
            </g>

            <!--Data Points - css classes to display value on hover - NOTE text value is displayed above dataPoint-->
            <!--
            <g class="first_set points" data-setname="Our first data set" id="dataPlot">
              <circle class="dataCircle" cx="150" cy="340" data-value="7.2" r="4"></circle><text class="dataValue hide" x="150" y="310">7.2</text>
              <circle class="dataCircle" cx="200" cy="315" data-value="8.1" r="4"></circle><text class="dataValue hide" x="200" y="285">4.2</text>
              <circle class="dataCircle" cx="250" cy="301" data-value="7.7" r="4"></circle><text class="dataValue hide" x="250" y="271">5.2</text> 
              <circle class="dataCircle" cx="300" cy="280" data-value="6.8" r="4"></circle><text class="dataValue hide" x="300" y="270">23.2</text>
              <circle class="dataCircle" cx="350" cy="249" data-value="6.7" r="4"></circle><text class="dataValue hide" x="350" y="239">32</text>  
              <circle class="dataCircle" cx="400" cy="245" data-value="5.7" r="4"></circle><text class="dataValue hide" x="400" y="235">7.2</text> 
              <circle class="dataCircle" cx="450" cy="242" data-value="6.7" r="4"></circle><text class="dataValue hide" x="450" y="232">8.2</text> 
              <circle class="dataCircle" cx="500" cy="238" data-value="6.8" r="4"></circle><text class="dataValue hide" x="500" y="228">752</text> 
              <circle class="dataCircle" cx="550" cy="230" data-value="4.7" r="4"></circle><text class="dataValue hide" x="550" y="220">22</text>  
              <circle class="dataCircle" cx="600" cy="222" data-value="5.7" r="4"></circle><text class="dataValue hide" x="600" y="212">7</text>   
              <circle class="dataCircle" cx="650" cy="220" data-value="2.7" r="4"></circle><text class="dataValue hide" x="650" y="210">7542</text>
              <circle class="dataCircle" cx="700" cy="218" data-value="6.9" r="4"></circle><text class="dataValue hide" x="700" y="208">42</text>  
            </g>
            -->

            <!--Hard coded Graph Line Data-->
            <g class="surfaces" id="lineData">
                <!--Line data-->
                <polyline fill="none" stroke="#000" stroke-width="1" stroke-dasharray="4, 1"
                points="100,500 150,~LINE_DATA1~ 200,~LINE_DATA2~ 250,~LINE_DATA3~ 300,~LINE_DATA4~ 350,~LINE_DATA5~ 400,~LINE_DATA6~ 450,~LINE_DATA7~ 500,~LINE_DATA8~ 550,~LINE_DATA9~ 600,~LINE_DATA10~ 650,~LINE_DATA11~ 700,~LINE_DATA12~"/>

            </g>
            
            <use class="grid double" xlink:href="#xGrid" ></use>
            <use class="grid double" xlink:href="#yGrid" ></use>
            
          </svg>


          <!-- ARRAY TO SVG - Appends data to graph container -->

          <!-- <coords-svg stroke="gold" stroke-dasharray="4, 1" coords="[[100,330],[ 150,332],[ 200,332],[ 250,335],[ 300,275],[ 350,281],[ 400,250],[ 450,241],[ 500,251],[ 550,133],[ 600,199],[ 650,172],[ 700,177]]"></coords-svg> -->
          <!-- <coords-svg stroke="green" coords="[[2, 15],[57, 58],[5, 57]]"></coords-svg> -->

          <!-- Converts custom <coord-svg> elements into valid polyline and appends to dataPlot. Next stage is to use JSON -->
          <!-- <script>
            customElements.define("coords-svg", class extends HTMLElement{
              connectedCallback(){
                let arr = JSON.parse(this.getAttribute("coords"));
                let dPath = arr.flat().join(" ");
                let stroke = this.getAttribute("stroke");
                this.style.display = "inline-block";
                
                var svgNS = "http://www.w3.org/2000/svg";
                let polyline = document.createElementNS(svgNS, "polyline");
                polyline.classList.add("dataLine");

                polyline.setAttribute("points", dPath);
                polyline.setAttribute("stroke", stroke);
                polyline.setAttribute("stroke-width", 1);
                polyline.setAttribute("fill", "none");

                document.getElementById("dataPlot").appendChild(polyline);
              }
            });
          </script> -->
         
          <!-- ARRAY TO SVG -->

        </div>  
    
        <!-- end lift graph -->


        <div class="align-center">
          <br>
          <button id="clear-graph-data-button" class="control-button">~LANG_GUI_CLEAR~</button> 
          <button id="export-graph-data-button" class="control-button">~LANG_GUI_EXPORT~</button> 
          <button id="export-graph-image-button" class="control-button">~LANG_GUI_IMAGE~</button> 
          <!-- Export button fires javascript function to click link below forcing the download-->
          <a href="/api/file/download/liftdata.json" download id="file-data-download" hidden></a>
        </div>

    </div>

)DATA";

return data;
}










/***********************************************************
 * @brief Settings
 *
 *
 *
 ***/
String PublicHTML::settings() {

    String settings PROGMEM = R"SETTINGS('

    <!-- File Manager Modal -->
    <div id="fileModal" class="modal">
        <div class="modal-content">
          <span class="closeFileModalButton">&times;</span>
          <h3>~LANG_GUI_FILE_MANAGER~</h3>
          <div id="file_list">~FILE_LIST~</div>
          <br>
          <hr>
          <br>
          <div class="float-right">
            <form method="POST" action="/api/file/upload" enctype="multipart/form-data">
              <div class="input_container">
                <input type="file" name="upload" id="fileUpload">
                <input type='submit' value='~LANG_GUI_FILEMANAGER_UPLOAD~' class="button file-submit-button">
              </div>
            </form>
          </div>
          <div class="clear-both">&nbsp;</div>
        </div>        
      </div>
  
      <!-- Info Modal -->
      <div id="infoModal" class="modal">
        <div class="info-modal-content row">
          <span class="closeInfoModalButton">&times;</span>
          <div class="row info-modal">
              <div class="column">
              <h4>~LANG_GUI_FIRMWARE~</h4>
              <hr>
              <div class="config-row"><label class="config-label">~LANG_GUI_VERSION~: </label><span class="config-value" id="RELEASE">~RELEASE~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_BUILD~:  </label><span class="config-value" id="BUILD_NUMBER">~BUILD_NUMBER~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_GUI~: </label><span class="config-value" id="VERSION">@@version@@</span></div>
              <h4>~LANG_GUI_STORAGE~</h4>
              <hr>
              <div class="config-row"><label class="config-label">~LANG_GUI_MEM_SIZE~:  </label><span class="config-value" id="SPIFFS_MEM_SIZE">~SPIFFS_MEM_SIZE~</span> (bytes)</div>
              <div class="config-row"><label class="config-label">~LANG_GUI_MEM_USED~:  </label><span class="config-value" id="SPIFFS_MEM_USED">~SPIFFS_MEM_USED~</span> (bytes)</div>
              <h4>~LANG_GUI_NETWORK~</h4>
              <hr>
              <div class="config-row"><label class="config-label">~LANG_GUI_IP_ADDRESS~:  </label><span class="config-value" id="LOCAL_IP_ADDRESS">~LOCAL_IP_ADDRESS~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_HOSTNAME~:  </label><span class="config-value" id="HOSTNAME">http://~HOSTNAME~.local</span></div>
            </div>
            <div class="column">
              <!-- <div class="config-row"><label class="config-label">Uptime:  </label><span class="config-value" id="UPTIME">~UPTIME~</span></div> -->
              <h4>~LANG_GUI_HARDWARE_CONFIG~</h4>
              <hr>
              <div class="config-row"><label class="config-label">~LANG_GUI_BENCH_TYPE~:  </label><span class="config-value" id="BENCH_TYPE">~BENCH_TYPE~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_BOARD_TYPE~:  </label><span class="config-value" id="BOARD_TYPE">~BOARD_TYPE~</span></div>
              <!-- <div class="config-row"><label class="config-label">Boot Time:  </label><span class="config-value" id="BOOT_TIME">~BOOT_TIME~</span></div> -->
              <h4>~LANG_GUI_SENS_CONFIG~</h4>
              <hr>
              <div class="config-row"><label class="config-label">~LANG_GUI_MAF_DATA_FILE~:  </label><span class="config-value" id="MAF_SENSOR"><a href="~MAF_LINK~" target="new">~MAF_SENSOR~</a></span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_REF_PRESSURE_SENSOR~:  </label><span class="config-value" id="PREF_SENSOR">~PREF_SENSOR~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_TEMP_SENSOR~:  </label><span class="config-value" id="TEMP_SENSOR">~TEMP_SENSOR~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_HUMIDITY_SENSOR~:  </label><span class="config-value" id="RELH_SENSOR">~RELH_SENSOR~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_BARO_SENSOR~:  </label><span class="config-value" id="BARO_SENSOR">~BARO_SENSOR~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_PITOT_SENSOR~:  </label><span class="config-value" id="PITOT_SENSOR">~PITOT_SENSOR~</span></div>
              <div class="config-row"><label class="config-label">~LANG_GUI_DIFFERENTIAL_SENSOR~:  </label><span class="config-value" id="PDIFF_SENSOR">~PDIFF_SENSOR~</span></div>
              </div>
            </div>
        </div>        
      </div>
        
  
    <!--Update modal-->
    <div id="updateModal" class="modal">
        <div class="modal-content updateModal">
          <span class="closeUpdateModalButton">&times;</span>
          <div class="align-center">
            <h3>~LANG_GUI_UPLOAD_FIRMWARE_BINARY~</h3>
            <hr>
            <br>
            <form method='POST' action='/api/update' enctype='multipart/form-data'>
              <div class="input_container">
                <input type="file" name="update" id="fileUpload">
                <input type='submit' value='~LANG_GUI_FIRMWARE_UPDATE~' class="button file-submit-button">
              </div>
            </form>
          </div>
        </div>        
      </div>





    <!-- configuration tab -->
    <div id="configuration" class="tabcontent tabcontentConfig">
        <div class="config-panel">
          <p style="text-align:center"><button id="file-manager-button" class="button">Files</button> <button id="info-button" class="button">Info</button> <button id="support-button" class="button" onclick="window.open('https://github.com/DeeEmm/DIY-Flow-Bench/wiki','_blank')">Support</button> <button id="restart-button" class="button" >Reboot</button> <button id="update-button" class="button">Update</button></p>       
          <br>
          <form method="POST" action="/api/saveconfig">
            <h2>~LANG_GUI_SYS_SETTINGS~</h2>
            <h3>~LANG_GUI_WIFI_INFO~</h3>        
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_WIFI_SSID~:</label>&nbsp;<input type="text" id="CONF_WIFI_SSID"  name="CONF_WIFI_SSID" value="~CONF_WIFI_SSID~" class="config-text" ><span class="tooltiptext">The name of your WiFi network</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_WIFI_PASS~:</label>&nbsp;<input type="text" id="CONF_WIFI_PSWD" name="CONF_WIFI_PSWD" value="~CONF_WIFI_PSWD~" class="config-text"><span class="tooltiptext">Your WiFi Password</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_WIFI_AP_SSID~:</label>&nbsp;<input type="text" id="CONF_WIFI_AP_SSID" name="CONF_WIFI_AP_SSID" value="~CONF_WIFI_AP_SSID~" class="config-text" ><span class="tooltiptext">Access-Point name for direct WiFi connection</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_WIFI_AP_PASS~:</label>&nbsp;<input type="text" id="CONF_WIFI_AP_PSWD" name="CONF_WIFI_AP_PSWD" value="~CONF_WIFI_AP_PSWD~" class="config-text"><span class="tooltiptext">Access-Point password</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_HOSTNAME~:</label>&nbsp;<input type="text" id="CONF_HOSTNAME" name="CONF_HOSTNAME" value="~CONF_HOSTNAME~" class="config-text"><span class="tooltiptext">DNS Hostname (used for connecting via URL e.g. http://diyfb.local)</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_WIFI_TIMEOUT~:</label>&nbsp;<input type="text" id="CONF_WIFI_TIMEOUT" name="CONF_WIFI_TIMEOUT" value="~CONF_WIFI_TIMEOUT~" class="config-text"><span class="tooltiptext">Number of milliseconds before WiFi retries connection</span></div>
            <br>
            <h3>~LANG_GUI_GENERAL_SETTINGS~</h3>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_BENCH_TYPE~:</label><span>~BENCH_TYPE_DROPDOWN~</span><span class="tooltiptext">Select bench type</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_MAF_HOUSING_DIAMETER~:</label>&nbsp;<input type="text" id="CONF_MAF_HOUSING_DIAMETER" name="CONF_MAF_HOUSING_DIAMETER" value="~CONF_MAF_HOUSING_DIAMETER~" class="config-text"><span class="tooltiptext">Diameter of MAF Housing. (Leave as zero to use standard housing diameter)</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_REFRESH_RATE~:</label>&nbsp;<input type="text" id="CONF_REFRESH_RATE" name="CONF_REFRESH_RATE" value="~CONF_REFRESH_RATE~" class="config-text"><span class="tooltiptext">Screen refresh rate in milliseconds</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_TEMPERATURE_UNIT~:</label><span>~TEMPERATURE_DROPDOWN~</span><span class="tooltiptext">Display unit of temperature</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_VALVE_LIFT_INTERVAL~:</label>&nbsp;<input type="text" id="VALVE_LIFT_INTERVAL" name="VALVE_LIFT_INTERVAL" value="~VALVE_LIFT_INTERVAL~" class="config-text"><span class="tooltiptext">Distance between valve lift data points</span></div>
            <br>
            <h3>~LANG_GUI_RESOLUTION_AND_ACCURACY~</h3>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_GEN_DECIMAL_ACCURACY~:</label>
              <span>~GEN_DECIMAL_LENGTH_DROPDOWN~</span>
              <span class="tooltiptext">Number of decimal places used in UI</span>
            </div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_FLOW_DECIMAL_ROUNDING~:</label>
              <span>~FLOW_DECIMAL_LENGTH_DROPDOWN~</span>
              <span class="tooltiptext">Number of decimal places used in UI for flow values</span>
            </div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_FLOW_VAL_ROUNDING~:</label>
              <span>~ROUNDING_TYPE_DROPDOWN~</span>
              <span class="tooltiptext">Rounding used in flow calculations</span>
            </div>
            <br>
            <h3>~LANG_GUI_DATA_FILTERS~</h3>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_DATA_FILTER_TYPE~:</label><span>~DATA_FILTER_TYPE_DROPDOWN~</span><span class="tooltiptext">Select data filter type</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_MIN_FLOW_RATE~:</label>&nbsp;<input type="text" id="CONF_MIN_FLOW_RATE" name="CONF_MIN_FLOW_RATE" value="~CONF_MIN_FLOW_RATE~" class="config-text"><span class="tooltiptext">Used to filter out non-zero flow values when bench is not running </span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_MIN_BENCH_PRESSURE~:</label>&nbsp;<input type="text" id="CONF_MIN_BENCH_PRESSURE" name="CONF_MIN_BENCH_PRESSURE" value="~CONF_MIN_BENCH_PRESSURE~" class="config-text"><span class="tooltiptext">Minimum reference pressure that bench is considered running</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_MAF_MIN_VOLTS~:</label>&nbsp;<input type="text" id="CONF_MAF_MIN_VOLTS" name="CONF_MAF_MIN_VOLTS" value="~CONF_MAF_MIN_VOLTS~" class="config-text"><span class="tooltiptext">Minimum MAF voltage that bench is considered running</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_CYCLIC_AVERAGE_BUFFER~:</label>&nbsp;<input type="text" id="CONF_CYCLIC_AVERAGE_BUFFER" name="CONF_CYCLIC_AVERAGE_BUFFER" value="~CONF_CYCLIC_AVERAGE_BUFFER~" class="config-text"><span class="tooltiptext">Mean buffer size - Used for smoothing results.</span></div>
            <br>
            <h3>~LANG_GUI_CONVERSION_SETTINGS~</h3>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ADJ_FLOW_DEPRESSION~:</label>&nbsp;<input type="text" id="ADJ_FLOW_DEPRESSION" name="ADJ_FLOW_DEPRESSION" value="~ADJ_FLOW_DEPRESSION~" class="config-text"><span class="tooltiptext">Bench depression used for adjusted flow calcs</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_STANDARD_REF_CONDITIONS~:</label>
              <select name='STANDARD_REFERENCE' class='config-select'>
                <option value='1' ~STD_REF_1~>ISO 5011 (20&degC(68&degF) 1atm(101.3kPa) 50%RH)</option>
                <option value='2' ~STD_REF_2~>ISO 1585 (25&degC(68&degF) 100kPa  0%RH)</option>
                <option value='3' ~STD_REF_3~>ISA (15&degC(59&degF) 1atm(101.325kPa)  0%RH)</option>
                <option value='4' ~STD_REF_4~>ISO 13443 (15&degC(59&degF) 1atm(101.325kPa)  0%RH)</option>
                <option value='5' ~STD_REF_5~>ISO 2533 (15&degC(59&degF) 1atm(101.325kPa)  0% RH)</option>
                <!--<option value='6'>NIST / EPA (20&degC(68&degF) 1atm(101.325kPa)  --RH(unspecified))</option>-->
              </select>
              <span class="tooltiptext">Standardised Temp, baro and humidity conditions.</span>
            </div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_STANDARDISED_ADJ_FLOW~:</label>&nbsp;<input type="checkbox" id="STD_ADJ_FLOW" name="STD_ADJ_FLOW" value="1" ~STD_ADJ_FLOW~ class="config-text"><span class="tooltiptext">Adjusted flow uses SCFM</span></div>
            <br>
            <h3>~LANG_GUI_DATA_CAPTURE_SETTINGS~</h3>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_CAPTURE_DATATYPE~:</label>
              <select name='DATA_COLLECTION_STANDARD' class='config-select'>
                <option value='1' ~CAP_MODE_1~>Flow (ACFM)</option>
                <option value='1' ~CAP_MODE_2~>Standard Flow (ACFM - ~STANDARD_FLOW~)</option>
                <option value='2' ~CAP_MODE_3~>Adjusted Flow (ACFM @ ~ADJ_FLOW_DEPRESSION~ in/H2O)</option>
                <option value='3' ~CAP_MODE_4~>Adjusted Standard Flow (ACFM - ~STANDARD_FLOW~ @ ~ADJ_FLOW_DEPRESSION~ in/H2O)</option>
                <option value='4' ~CAP_MODE_5~>MAF Flow (~MAF_FLOW_UNIT~)</option>
              </select>
              <span class="tooltiptext">Default data type for data capture.</span>
            </div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_DATA_GRAPH_MAX_VAL~:</label>
              <select name='DATAGRAPH_MAX' class='config-select'>
                <option value='0' ~DATAGRAPH_MAX_0~>~LANG_GUI_AUTO~</option>
                <option value='1' ~DATAGRAPH_MAX_1~>250 cfm</option>
                <option value='2' ~DATAGRAPH_MAX_2~>500 cfm</option>
                <option value='3' ~DATAGRAPH_MAX_3~>1000 cfm</option>
              </select>
              <span class="tooltiptext">Set max scaling for Data Graph.</span>
            </div>
            <br>
            <h3>~LANG_GUI_CAL_ORIFICE_SETTINGS~</h3>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_CAL_ORIFICE_FLOW_RATE~:</label>&nbsp;<input type="text" id="CONF_CAL_FLOW_RATE" name="CONF_CAL_FLOW_RATE" value="~CONF_CAL_FLOW_RATE~" class="config-text"><span class="tooltiptext">Flow rate of calibration orifice in cfm</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_CAL_ORIFICE_TEST_PRESS~:</label>&nbsp;<input type="text" id="CONF_CAL_REF_PRESS" name="CONF_CAL_REF_PRESS" value="~CONF_CAL_REF_PRESS~" class="config-text"><span class="tooltiptext">Reference depression of calibration orifice in in/wg</span></div>
            <br>
            <div id="orificeData">
              <h3>~LANG_GUI_ORIFICE_DATA~</h3>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE1_FLOW~:</label>&nbsp;<input type="text" id="ORIFICE1_FLOW_RATE" name="ORIFICE1_FLOW_RATE" value="~ORIFICE1_FLOW_RATE~" class="config-text"><span class="tooltiptext">Flow rate of orifice #1 in cfm</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE1_PRESSURE~:</label>&nbsp;<input type="text" id="ORIFICE1_TEST_PRESSURE" name="ORIFICE1_TEST_PRESSURE" value="~ORIFICE1_TEST_PRESSURE~" class="config-text"><span class="tooltiptext">Test Pressure for orifice #1 in in/wg</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE2_FLOW~:</label>&nbsp;<input type="text" id="ORIFICE2_FLOW_RATE" name="ORIFICE2_FLOW_RATE" value="~ORIFICE2_FLOW_RATE~" class="config-text"><span class="tooltiptext">Flow rate of orifice #2 in cfm</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE2_PRESSURE~:</label>&nbsp;<input type="text" id="ORIFICE2_TEST_PRESSURE" name="ORIFICE2_TEST_PRESSURE" value="~ORIFICE2_TEST_PRESSURE~" class="config-text"><span class="tooltiptext">Test Pressure for orifice #2 in in/wg</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE3_FLOW~:</label>&nbsp;<input type="text" id="ORIFICE3_FLOW_RATE" name="ORIFICE3_FLOW_RATE" value="~ORIFICE3_FLOW_RATE~" class="config-text"><span class="tooltiptext">Flow rate of orifice #3 in cfm</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE3_PRESSURE~:</label>&nbsp;<input type="text" id="ORIFICE3_TEST_PRESSURE" name="ORIFICE3_TEST_PRESSURE" value="~ORIFICE3_TEST_PRESSURE~" class="config-text"><span class="tooltiptext">Test Pressure for orifice #3 in in/wg</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE4_FLOW~:</label>&nbsp;<input type="text" id="ORIFICE4_FLOW_RATE" name="ORIFICE4_FLOW_RATE" value="~ORIFICE4_FLOW_RATE~" class="config-text"><span class="tooltiptext">Flow rate of orifice #4 in cfm</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE4_PRESSURE~:</label>&nbsp;<input type="text" id="ORIFICE4_TEST_PRESSURE" name="ORIFICE4_TEST_PRESSURE" value="~ORIFICE4_TEST_PRESSURE~" class="config-text"><span class="tooltiptext">Test Pressure for orifice #4 in in/wg</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE5_FLOW~:</label>&nbsp;<input type="text" id="ORIFICE5_FLOW_RATE" name="ORIFICE5_FLOW_RATE" value="~ORIFICE5_FLOW_RATE~" class="config-text"><span class="tooltiptext">Flow rate of orifice #5 in cfm</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE5_PRESSURE~:</label>&nbsp;<input type="text" id="ORIFICE5_TEST_PRESSURE" name="ORIFICE5_TEST_PRESSURE" value="~ORIFICE5_TEST_PRESSURE~" class="config-text"><span class="tooltiptext">Test Pressure for orifice #5 in in/wg</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE6_FLOW~:</label>&nbsp;<input type="text" id="ORIFICE6_FLOW_RATE" name="ORIFICE6_FLOW_RATE" value="~ORIFICE6_FLOW_RATE~" class="config-text"><span class="tooltiptext">Flow rate of orifice #6 in cfm</span></div>
              <div class="config-row tooltip"><label class="config-label">~LANG_GUI_ORIFICE6_PRESSURE~:</label>&nbsp;<input type="text" id="ORIFICE6_TEST_PRESSURE" name="ORIFICE6_TEST_PRESSURE" value="~ORIFICE6_TEST_PRESSURE~" class="config-text"><span class="tooltiptext">Test Pressure for orifice #6 in in/wg</span></div>
              <br>
            </div>
            <br>
            <h3>~LANG_GUI_API_SETTINGS~</h3>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_API_DELIMITER~:</label>&nbsp;<input type="text" id="CONF_API_DELIM" name="CONF_API_DELIM" value="~CONF_API_DELIM~" class="config-text"><span class="tooltiptext">Character used to delimit API / Serial data </span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_SERIAL_BAUD_RATE~:</label>&nbsp;<input type="text" id="CONF_SERIAL_BAUD_RATE" name="CONF_SERIAL_BAUD_RATE" value="~CONF_SERIAL_BAUD_RATE~" class="config-text"><span class="tooltiptext">Baud rate for serial communication</span></div>
            <div class="float-right"><input id="save-config-button" type="submit" class="button" value="Save"></div>
            <br>
            <br>
          </form>
          <br>
          <br>
          <form method="POST" action="/api/savecalibration">
            <h2>~LANG_GUI_CALIBRATION_DATA~</h2>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_CAL_OFFSET~:</label>&nbsp;<input type="text" id="FLOW_OFFSET" name="FLOW_OFFSET" value="~FLOW_OFFSET~" class="config-text"><span class="tooltiptext">Measured calibration offset</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_LEAK_TEST_BASELINE~:</label>&nbsp;<input  type="text" id="LEAK_CAL_BASELINE" name="LEAK_CAL_BASELINE" value="~LEAK_CAL_BASELINE~" class="config-text"><span class="tooltiptext">Baseline Offset</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_LEAK_TEST_OFFSET~:</label>&nbsp;<input  type="text" id="LEAK_CAL_OFFSET" name="LEAK_CAL_OFFSET" value="~LEAK_CAL_OFFSET~" class="config-text"><span class="tooltiptext">Measured leak test value</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_LEAK_TEST_BASELINE_REV~:</label>&nbsp;<input  type="text" id="LEAK_CAL_BASELINE_REV" name="LEAK_CAL_BASELINE_REV" value="~LEAK_CAL_BASELINE_REV~" class="config-text"><span class="tooltiptext">Baseline Offset (Reverse Flow)</span></div>
            <div class="config-row tooltip"><label class="config-label">~LANG_GUI_LEAK_TEST_OFFSET_REV~:</label>&nbsp;<input type="text" id="LEAK_CAL_OFFSET_REV" name="LEAK_CAL_OFFSET_REV" value="~LEAK_CAL_OFFSET_REV~" class="config-text"><span class="tooltiptext">Measured leak test value (Reverse Flow)</span></div>
            <br>
            <div class="float-right"><input id="save-config-button" type="submit" class="button" value="~LANG_GUI_OVERWRITE~"></div>
          </form>
        </div>                    
      </div>
    </div>
  
  
)SETTINGS";

return settings;
}








/***********************************************************
 * @brief Get Main Javscript
 *
 *
 *
 ***/

String PublicHTML::mainJs() {

  String mainJs PROGMEM = R"MAINJS(

var updateSSE = true;
var activeOrifice;
var runOnce = false;

window.addEventListener('load', onLoad);

var captureLiftDataModal = document.getElementById("captureLiftDataModal");
var calibrationModal = document.getElementById("calibrationModal");
var flowTargetModal = document.getElementById("flowTargetModal");

var closeFlowTargetModalButton = document.getElementsByClassName("closeFlowTargetModalButton")[0];
var closeCalibrationModalButton = document.getElementsByClassName("closeCalibrationModalButton")[0];
var closeCaptureLiftDataModalButton = document.getElementsByClassName("closeCaptureLiftDataModalButton")[0];
var closeCalibrationModalButton = document.getElementsByClassName("closeCalibrationModalButton")[0];

// Set up Server Side Events (SSE)
if (!!window.EventSource) {
  var source = new EventSource('/events');

  source.addEventListener('JSON_DATA', function(e) {
    var myObj = JSON.parse(e.data);

    if (updateSSE === true){

      for (key in myObj) {
        try {
          if (typeof myObj[key] === 'string' || myObj[key] instanceof String) {
          // We've got a string...
            if (key === 'PITOT_COLOUR' || key === 'PDIFF_COLOUR' ) {
            } else {
              // it' a template variable
              document.getElementById(key).innerHTML = myObj[key];
            }
 
          } else {
           // we've not got a string... 
           if (key === 'FLOW' || key === 'AFLOW' || key === 'MFLOW' || key === 'SFLOW' || key === 'FDIFF') {
              // HACK: template vars - replaced before page load
              // document.getElementById(key).innerHTML = myObj[key].toFixed(~FLOW_DECIMAL_LENGTH~);  
              document.getElementById(key).innerHTML = myObj[key].toFixed(2);  
            } else if (key === 'PREF' || key === 'PDIFF' || key === 'PITOT' || key === 'PITOT_DELTA' || key === 'SWIRL' || key === 'TEMP' || key === 'BARO' || key === 'RELH') {
              // document.getElementById(key).innerHTML = myObj[key].toFixed(~GEN_DECIMAL_LENGTH~); 
              document.getElementById(key).innerHTML = myObj[key].toFixed(2); 
            //} else if (key === '') {
            } else {
              document.getElementById(key).innerHTML = myObj[key];
            }
          }
        } catch (error) {
          console.log('Missing or incorrect JSON data');
          console.log(" error: " + error + " key: " + key );
          // console.log(key);
        }
      } 

      // get bench type and set up GUI accoordingly
      var benchType = myObj["BENCH_TYPE"];

      // get active orifice and set up GUI accoordingly
      activeOrifice = myObj["ACTIVE_ORIFICE"];
      if (runOnce == false ){
        radioButton = document.getElementById("orifice" + activeOrifice);
        radioButton.checked = true;
      }

      switch (benchType) {
    
        case "MAF":
          document.getElementById('orificeData').style.display='none';
          document.getElementById('orificeRadio').style.display='none';
        break;
    
        case "ORIFICE":
          document.getElementById('orificeData').style.display='block';
          document.getElementById('orificeRadio').style.display='block';
        break;
          
        case "VENTURI":
          document.getElementById('orificeData').style.display='block';
        break;
          
        case "PITOT":
          document.getElementById('orificeData').style.display='block';
        break;
          
      }

      // Get data filter type
      var dataFilterType = myObj["DATA_FILTER_TYPE"];

      // Get Pitot Tile status colours
      var pitotTileColour = myObj["PITOT_COLOUR"];
      document.getElementById('PITOT').style.color=pitotTileColour;

      // Get pDiff tile tatus colours
      var pDiffTileColour = myObj["PDIFF_COLOUR"];
      document.getElementById('PDIFF').style.color=pDiffTileColour;
    }

  }, false);

}

function setCookie(name,value,days) {
  var expires = "";
  if (days) {
      var date = new Date();
      date.setTime(date.getTime() + (days*24*60*60*1000));
      expires = "; expires=" + date.toUTCString();
  }
  document.cookie = name + "=" + (value || "")  + expires + "; path=/";
}

function getCookie(name) {
  var nameEQ = name + "=";
  var ca = document.cookie.split(';');
  for(var i=0;i < ca.length;i++) {
      var c = ca[i];
      while (c.charAt(0)==' ') c = c.substring(1,c.length);
      if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
  }
  return null;
}

// https://github.com/Autodrop3d/serialTerminal.com
function changeCookieValue(cookieName, newValue) {
  document.cookie = 
      `${cookieName}=${newValue}; 
          expires=Thu, 5 March 2030 12:00:00 UTC; path=/`;
}

  )MAINJS";

  return mainJs;

}








/***********************************************************
 * @brief Get Javscript
 *
 *
 *
 ***/

String PublicHTML::indexJs() {

  String indexJs PROGMEM = R"INDEXJS(
/***********************************************************
* onLoad event handler
***/
function onLoad(event) {

    initialiseButtons();
   
    // Set tile status on page reload from cookie data
    var tileStatus = getCookie('pressure-tile');
    
    switch (tileStatus) {
  
      case "pdiff":
        document.getElementById('tile-pref').style.display='none';
        document.getElementById('tile-pdiff').style.display='block';
      break;
  
      case "pref":
        document.getElementById('tile-pref').style.display='block';
        document.getElementById('tile-pdiff').style.display='none';
      break;
  
    }
  
    var tileStatus = getCookie('flow-tile');
  
    switch (tileStatus){
  
      case "flow":
        document.getElementById('flow-tile').style.display='block';
        document.getElementById('aflow-tile').style.display='none';
        document.getElementById('sflow-tile').style.display='none';
        document.getElementById('maf-tile').style.display='none';
      break;
  
      case "aflow":
        document.getElementById('flow-tile').style.display='none';
        document.getElementById('aflow-tile').style.display='block';
        document.getElementById('sflow-tile').style.display='none';
        document.getElementById('maf-tile').style.display='none';
      break;
  
      case "sflow":
        document.getElementById('flow-tile').style.display='none';
        document.getElementById('aflow-tile').style.display='none';
        document.getElementById('sflow-tile').style.display='block';
        document.getElementById('maf-tile').style.display='none';
      break;
  
      case "maf":
        document.getElementById('flow-tile').style.display='none';
        document.getElementById('aflow-tile').style.display='none';
        document.getElementById('sflow-tile').style.display='none';
        document.getElementById('maf-tile').style.display='block';
      break;
  
    }
  
    var tileStatus = getCookie('tool-tile');
  
    switch (tileStatus){
  
      case "pitot":
        document.getElementById('tile-pitot').style.display='block';
        document.getElementById('tile-swirl').style.display='none';
        document.getElementById('tile-fdiff').style.display='none';
      break;
  
      case "swirl":
        document.getElementById('tile-pitot').style.display='none';
        document.getElementById('tile-swirl').style.display='block';
        document.getElementById('tile-fdiff').style.display='none';
      break;
  
      case "fdiff":
        document.getElementById('tile-pitot').style.display='none';
        document.getElementById('tile-swirl').style.display='none';
        document.getElementById('tile-fdiff').style.display='block';
      break;
    
    }
  
    console.log('Page Loaded');
    
  }
  
/***********************************************************
* Initialise buttons
***/
function initialiseButtons() {
  
    var xhr = new XMLHttpRequest();
  
    document.getElementById('show-capture-modal-button').addEventListener('click', function(){
      document.getElementById('captureLiftDataModal').style.display='block';
    });
  
    document.getElementById('FDIFF').addEventListener('click', function(){
      document.getElementById('flowTargetModal').style.display='block';
    });
  
    document.getElementById('capture-lift-data-button').addEventListener('click', function(){
      console.log('Capture Lift Data');
      let formData = new FormData(document.forms.lift_data_form);
      xhr.open('POST', '/api/saveliftdata');
      xhr.send(formData)
      xhr.onload = function() {
        if (xhr.status === 200) {
          console.log('Lift data saved');
          // update datagraph
        }
  
      };
    });
  
    document.getElementById('STATUS_MESSAGE').addEventListener('dblclick', function(){
      document.getElementById('calibrationModal').style.display='block';
    });

    // Pressure tile
    document.getElementById('tile-pref-title').addEventListener('click', function(){
      document.getElementById('tile-pref').style.display='none';
      document.getElementById('tile-pdiff').style.display='block';
      setCookie("pressure-tile","pdiff","365")    
    });
  
    document.getElementById('tile-pdiff-title').addEventListener('click', function(){
      document.getElementById('tile-pdiff').style.display='none';
      document.getElementById('tile-pref').style.display='block';
      setCookie("pressure-tile","pref","365")
    });
  
    // flow tile
    document.getElementById('flow-tile-title').addEventListener('click', function(){
      document.getElementById('flow-tile').style.display='none';
      document.getElementById('aflow-tile').style.display='block';
      setCookie("flow-tile","aflow","365")    
    });
  
    document.getElementById('aflow-tile-title').addEventListener('click', function(){
      document.getElementById('aflow-tile').style.display='none';
      document.getElementById('sflow-tile').style.display='block';
      setCookie("flow-tile","sflow","365")    
    });
  
    document.getElementById('sflow-tile-title').addEventListener('click', function(){
      document.getElementById('sflow-tile').style.display='none';
      document.getElementById('maf-tile').style.display='block';
      setCookie("flow-tile","maf","365")    
    });
  
    document.getElementById('maf-tile-title').addEventListener('click', function(){
      document.getElementById('maf-tile').style.display='none';
      document.getElementById('flow-tile').style.display='block';
      setCookie("flow-tile","flow","365")    
    });
  
    // Tool tile
    document.getElementById('tile-pitot-title').addEventListener('click', function(){
      document.getElementById('tile-pitot').style.display='none';
      document.getElementById('tile-swirl').style.display='block';
      setCookie("tool-tile","swirl","365")    
    });
  
    document.getElementById('tile-swirl-title').addEventListener('click', function(){
      document.getElementById('tile-swirl').style.display='none';
      document.getElementById('tile-fdiff').style.display='block';
      setCookie("tool-tile","fdiff","365")    
    });
  
    document.getElementById('tile-fdiff-title').addEventListener('click', function(){
      document.getElementById('tile-fdiff').style.display='none';
      document.getElementById('tile-pitot').style.display='block';
      setCookie("tool-tile","pitot","365")    
    });
  
    document.getElementById('FDIFFTYPEDESC').addEventListener('click', function(){
      console.log('Toggle Flow Diff');
      xhr.open('GET', '/api/fdiff/toggle');
      // xhr.onload = function() {
      //   if (xhr.status === 200) window.location.href = '/';
      // };
      xhr.send();
    });
  
    document.getElementById('PDIFF').addEventListener('click', function(){
      console.log('Zero pDiff Value');
      xhr.open('GET', '/api/pdiff/zero');
      // xhr.onload = function() {
      //   if (xhr.status === 200) window.location.href = '/';
      // };
      xhr.send();
    });
  
    document.getElementById('PITOT').addEventListener('click', function(){
      console.log('Zero Pitot Value');
      xhr.open('GET', '/api/pitot/zero');
      // xhr.onload = function() {
      //   if (xhr.status === 200) window.location.href = '/';
      // };
      xhr.send();
    });
  
    document.getElementById('on-button').addEventListener('click', function(){
      console.log('Bench On');
      xhr.open('GET', '/api/bench/on');
      // xhr.onload = function() {
      //   if (xhr.status === 200) window.location.href = '/';
      // };
      xhr.send();
    });
  
    document.getElementById('off-button').addEventListener('click', function(){
      console.log('Bench Off');
      xhr.open('GET', '/api/bench/off');
      // xhr.onload = function() {
      //   if (xhr.status === 200) window.location.href = '/';
      // };
      xhr.send();
    });
  
    document.getElementById('calibrate-button').addEventListener('click', function(){
      console.log('Calibrate FLow Offset');
      xhr.open('GET', '/api/bench/calibrate');
      xhr.onload = function() {
        if (xhr.status === 200) window.location.href = '/?view=config';
      };
      xhr.send();
    });
  
    document.getElementById('leak-cal-button').addEventListener('click', function(){
      console.log('Leak Test Calibration');
      xhr.open('GET', '/api/bench/leakcal');
      xhr.onload = function() {
        if (xhr.status === 200) window.location.href = '/?view=config';
      };
      xhr.send();
    });
  
    document.getElementById('clear-message-button').addEventListener('click', function(){
      console.log('Clear Message');
      xhr.open('GET', '/api/clear-message');
      xhr.onload = function() {
        if (xhr.status === 200) window.location.href = '/';
      };
      xhr.send();
    });
  
  }
  
  /***********************************************************
* Update selected orifice when orifice-radio button change
***/
function orificeChange(src) {
  
    var xhr = new XMLHttpRequest();
  
    console.log('Orifice ' + src.value + ' Selected');
  
    xhr.open('GET', '/api/orifice-change?orifice=' + src.value);
    xhr.onload = function() {
  //    if (xhr.status === 200) window.location.href = '/';
    };
    xhr.send();
    }
  
/***********************************************************
* Close modal dialogs on lose focus
***/
window.onclick = function(event) {
    if (event.target == captureLiftDataModal || event.target == calibrationModal || event.target == flowTargetModal  ){
      captureLiftDataModal.style.display = "none";
      calibrationModal.style.display = "none";
      flowTargetModal.style.display = "none";
    }
  }
  
  /***********************************************************
  * Close modal dialogs on esc button
  ***/
  document.addEventListener("keydown", ({key}) => {
    if (key === "Escape") {
      captureLiftDataModal.style.display = "none";
      calibrationModal.style.display = "none";
      flowTargetModal.style.display = "none";
    }
  })

    /***********************************************************
  * Close calibration modal dialog
  ***/
  closeCalibrationModalButton.onclick = function() {
    calibrationModal.style.display = "none";
  }

  /***********************************************************
  * Close Capture Data modal dialog
  ***/
  closeCaptureLiftDataModalButton.onclick = function() {
    captureLiftDataModal.style.display = "none";
  }

  /***********************************************************
  * Close Flow Target Data modal dialog
  ***/
  closeFlowTargetModalButton.onclick = function() {
    flowTargetModal.style.display = "none";
  }
  )INDEXJS";

  return indexJs;

}







/***********************************************************
 * @brief Get CSS
 *
 *
 *
 ***/
String PublicHTML::css () {


  String css PROGMEM = R"CSS(

  /* Set height of body and the document to 100 percent of viewport height to enable "full page tabs" */
  body, html {
    height: 100vh;
    margin: 0;
    font-family: Arial;
    font-size:22px;
    /* "large triangles" SVG background by SVGBackgrounds.com/ */
    background-color: #FFFFFF;
    background-image: url("data:image/svg+xml,%3Csvg xmlns="http://www.w3.org/2000/svg" width="562" height="468.3" viewBox="0 0 1080 900"%3E%3Cg fill-opacity="0.03"%3E%3Cpolygon fill="%23444" points="90 150 0 300 180 300"/%3E%3Cpolygon points="90 150 180 0 0 0"/%3E%3Cpolygon fill="%23AAA" points="270 150 360 0 180 0"/%3E%3Cpolygon fill="%23DDD" points="450 150 360 300 540 300"/%3E%3Cpolygon fill="%23999" points="450 150 540 0 360 0"/%3E%3Cpolygon points="630 150 540 300 720 300"/%3E%3Cpolygon fill="%23DDD" points="630 150 720 0 540 0"/%3E%3Cpolygon fill="%23444" points="810 150 720 300 900 300"/%3E%3Cpolygon fill="%23FFF" points="810 150 900 0 720 0"/%3E%3Cpolygon fill="%23DDD" points="990 150 900 300 1080 300"/%3E%3Cpolygon fill="%23444" points="990 150 1080 0 900 0"/%3E%3Cpolygon fill="%23DDD" points="90 450 0 600 180 600"/%3E%3Cpolygon points="90 450 180 300 0 300"/%3E%3Cpolygon fill="%23666" points="270 450 180 600 360 600"/%3E%3Cpolygon fill="%23AAA" points="270 450 360 300 180 300"/%3E%3Cpolygon fill="%23DDD" points="450 450 360 600 540 600"/%3E%3Cpolygon fill="%23999" points="450 450 540 300 360 300"/%3E%3Cpolygon fill="%23999" points="630 450 540 600 720 600"/%3E%3Cpolygon fill="%23FFF" points="630 450 720 300 540 300"/%3E%3Cpolygon points="810 450 720 600 900 600"/%3E%3Cpolygon fill="%23DDD" points="810 450 900 300 720 300"/%3E%3Cpolygon fill="%23AAA" points="990 450 900 600 1080 600"/%3E%3Cpolygon fill="%23444" points="990 450 1080 300 900 300"/%3E%3Cpolygon fill="%23222" points="90 750 0 900 180 900"/%3E%3Cpolygon points="270 750 180 900 360 900"/%3E%3Cpolygon fill="%23DDD" points="270 750 360 600 180 600"/%3E%3Cpolygon points="450 750 540 600 360 600"/%3E%3Cpolygon points="630 750 540 900 720 900"/%3E%3Cpolygon fill="%23444" points="630 750 720 600 540 600"/%3E%3Cpolygon fill="%23AAA" points="810 750 720 900 900 900"/%3E%3Cpolygon fill="%23666" points="810 750 900 600 720 600"/%3E%3Cpolygon fill="%23999" points="990 750 900 900 1080 900"/%3E%3Cpolygon fill="%23999" points="180 0 90 150 270 150"/%3E%3Cpolygon fill="%23444" points="360 0 270 150 450 150"/%3E%3Cpolygon fill="%23FFF" points="540 0 450 150 630 150"/%3E%3Cpolygon points="900 0 810 150 990 150"/%3E%3Cpolygon fill="%23222" points="0 300 -90 450 90 450"/%3E%3Cpolygon fill="%23FFF" points="0 300 90 150 -90 150"/%3E%3Cpolygon fill="%23FFF" points="180 300 90 450 270 450"/%3E%3Cpolygon fill="%23666" points="180 300 270 150 90 150"/%3E%3Cpolygon fill="%23222" points="360 300 270 450 450 450"/%3E%3Cpolygon fill="%23FFF" points="360 300 450 150 270 150"/%3E%3Cpolygon fill="%23444" points="540 300 450 450 630 450"/%3E%3Cpolygon fill="%23222" points="540 300 630 150 450 150"/%3E%3Cpolygon fill="%23AAA" points="720 300 630 450 810 450"/%3E%3Cpolygon fill="%23666" points="720 300 810 150 630 150"/%3E%3Cpolygon fill="%23FFF" points="900 300 810 450 990 450"/%3E%3Cpolygon fill="%23999" points="900 300 990 150 810 150"/%3E%3Cpolygon points="0 600 -90 750 90 750"/%3E%3Cpolygon fill="%23666" points="0 600 90 450 -90 450"/%3E%3Cpolygon fill="%23AAA" points="180 600 90 750 270 750"/%3E%3Cpolygon fill="%23444" points="180 600 270 450 90 450"/%3E%3Cpolygon fill="%23444" points="360 600 270 750 450 750"/%3E%3Cpolygon fill="%23999" points="360 600 450 450 270 450"/%3E%3Cpolygon fill="%23666" points="540 600 630 450 450 450"/%3E%3Cpolygon fill="%23222" points="720 600 630 750 810 750"/%3E%3Cpolygon fill="%23FFF" points="900 600 810 750 990 750"/%3E%3Cpolygon fill="%23222" points="900 600 990 450 810 450"/%3E%3Cpolygon fill="%23DDD" points="0 900 90 750 -90 750"/%3E%3Cpolygon fill="%23444" points="180 900 270 750 90 750"/%3E%3Cpolygon fill="%23FFF" points="360 900 450 750 270 750"/%3E%3Cpolygon fill="%23AAA" points="540 900 630 750 450 750"/%3E%3Cpolygon fill="%23FFF" points="720 900 810 750 630 750"/%3E%3Cpolygon fill="%23222" points="900 900 990 750 810 750"/%3E%3Cpolygon fill="%23222" points="1080 300 990 450 1170 450"/%3E%3Cpolygon fill="%23FFF" points="1080 300 1170 150 990 150"/%3E%3Cpolygon points="1080 600 990 750 1170 750"/%3E%3Cpolygon fill="%23666" points="1080 600 1170 450 990 450"/%3E%3Cpolygon fill="%23DDD" points="1080 900 1170 750 990 750"/%3E%3C/g%3E%3C/svg%3E");  
  }

  h4 {
    margin-bottom: 0px;
  }

  /* Set tabs to 50 percent of viewport width */
  .tablink {
    background-color: #555;
    color: white;
    float: left;
    border: none;
    outline: none;
    cursor: pointer;
    padding: 18px 16px;
    font-size: 22px;
    width: 33.3333%;
  }

  .tablink:active {
    background-color: #777;
  }

  .tablink:hover {
    background-color: #777;
  }

  #tabcontainer {
    padding: 100px 20px 20px 20px;

  }

  /* Style the tab content (and add height:100% of viewport height for full page content) */
  .tabcontentMain {
    display:block;
  }

  .tabcontentConfig {
    display: none;
    margin-bottom: 60px;
  }

  .tabcontentData {
    display: none;
  }

  #Home {background-color: white;}
  #News {background-color: white;}
  #Contact {background-color: white;}
  #About {background-color: white;}

  html {
    font-family: Helvetica;
    display: inline-block;
    margin: 0px auto;
  }

  .headerbar {
    overflow: hidden;
    background-color: #0A1128;
    text-align: center;
  }

  .headerbar h1 a:link, .headerbar h1 a:active, .headerbar h1 a:visited, .headerbar h1 a:hover {
    color:white;
    text-decoration: none;
    font-size: 44px;
    font-weight: bold;
  }

  h1 {
    font-size: 30px;
  }

  h2 {
    font-size: 26px;
    margin-bottom: 14px;
  }

  h3 {
    font-size: 20px;
  }

  p{
    font-size: 1.5rem;
  }

  a:link  {
    color:#0A1128;
    text-decoration:none;
  }

  a:visited, a:active {
    color:#0A1128;
    text-decoration:none;
  }

  a:hover {
    color:#666;
    text-decoration:none;
  }

  hr {
    clear: both;
    width: 95%;
  }

  .content {
    padding: 30px;
  }

  .float-right{
    float:right;
  }

  .clear-both{
    clear:both;
  }

  .align-center{
    text-align: center;
  }

  .clear-both {
    clear:both;
  }

  .tile-grid {
    max-width: 700px;
    margin: 0 auto;
    display: grid;
    grid-gap: 2rem;
    grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
  }

  .tile {
    background-color: white;
    box-shadow: 2px 2px 12px 1px #666;
    text-align: center;
  }

  .tile-title {
    font-size: 1rem;
    font-weight: bold;
    color: #034078;
    cursor: pointer;
  }

  .tile-value {
    font-size: 2.1rem;
    font-weight: bold;
    color: #333;
  }

  .pitot-tile-value {
    font-size: 2.1rem;
    font-weight: bold;
    color: ~PITOT_COLOUR~;
  }

  .differential-tile-value {
    font-size: 2.1rem;
    font-weight: bold;
    color: ~PDIFF_COLOUR~;
  }

  #FDIFFTYPEDESC, #PDIFF, #PITOT {
    cursor: pointer;
  }

  .flowTargetVal {
    font-weight: bold;
    font-size: 2.1rem;
    color: #333;
    cursor: pointer;
  }

  flowTargetValInput {
    font-size: 22px;
  }

  #tile-pdiff, #aflow-tile, #maf-tile, #tile-swirl, #tile-fdiff, #sflow-tile  {
    display: none;
  }


  .config-panel {
    max-width: 650px;
    margin: auto auto;
  }

  .config-row {
    margin-top: 5px;
    margin-top: 5px;
  }

  .config-label {
    padding-left: 5px;
  }

  .config-value {
    padding-right: 10px;
    float: right;
  }

  .config-text {
    width: 200px;
    float: right;
  }

  .config-select {
    width: 208px;
    float: right;
  }

  .units {
    font-size: 0.8rem;
    color:#666;
  }

  .status_message {
    font-size: 1.2rem;
    color:#666;
    margin-bottom: 28px;
  }

  #footer {
    margin-top:30px;
    clear:both;
    text-align: center;
  }

  .hidden_div {
    display:none;
  }

  /***
  * Buttons
  */

  .control-button {
    display: inline-block;
    background-color: #008CBA;
    border: none;
    border-radius: 4px;
    color: white;
    padding: 12px 12px;
    text-decoration: none;
    font-size: 22px;
    margin: 2px;
    cursor: pointer;
    width: 150px;
    height: 70px;
  }

  .button {
    display: inline-block;
    background-color: #008CBA;
    border: none;
    border-radius: 4px;
    color: white;
    padding: 12px 12px;
    text-decoration: none;
    font-size: 22px;
    margin: 2px;
    cursor: pointer;
    width: 150px;
  }

  .button-sml {
    float:right;
    background-color: #008CBA;
    border: none;
    border-radius: 4px;
    color: white;
    padding: 6px 6px;
    text-decoration: none;
    font-size: 12px;
    margin: 2px;
    cursor: pointer;
  }

  #record-button {
    background-color: #fa7b04;
  }

  #clear-graph-data-button {
    background-color: #fa7b04;
  }

  #export-graph-data-button {
    background-color: #2ca909;
  }

  #load-graph-data-button {
    background-color: #125ab1;
  }

  #save-graph-data-button {
    background-color: #fa7b04;
  }

  #calibrate-button{
    background-color: #fa2e04;
  }

  #clear-message-button {
    background-color: #999;
  }

  #info-button, #support-button,  #file-manager-button, #restart-button, #update-button {
    width:110px;
    height: 50px;
  }


  #on-button {
    background-color: #44b112;
  }

  #off-button {
    background-color: #fa2e04;
  }

  #delete-button, #restart-button {
    background-color: #fa2e04;
  }

  #upload-form {
    float:right;
  }


  .tooltip {
    position: relative;
    border-bottom: 1px dotted black;
  }

  .tooltip .tooltiptext {
    visibility: hidden;
    width: 350px;
    background-color: #666;
    color: #fff;
    text-align: center;
    border-radius: 6px;
    padding: 5px 5px;
    position: absolute;
    z-index: 1;
    left: -10px;
    top: -5px;
  }

  .tooltip .tooltiptext::after {
    content: "";
    position: absolute;
    top: 100vh;
    left: 50%;
    margin-left: -5px;
    border-width: 5px;
    border-style: solid;
    border-color: black transparent transparent transparent;
  }

  .tooltip:hover .tooltiptext {
    visibility: visible;
  }

  /* Modal Dialogs */
  .modal {
    display: none; /* Hidden by default */
    position: fixed; /* Stay in place */
    z-index: 1; /* Sit on top */
    left: 0;
    padding-top: 50px;
    width: 100vw; /* Full width */
    height: 100vh; /* Full height */
    overflow: auto; /* Enable scroll if needed */
    background-color: rgb(0,0,0); /* Fallback color */
    background-color: rgba(0,0,0,0.4); /* Black w/ opacity */
  }


  /* Modal Content/Box */
  .modal-content {
    background-color: #fefefe;
    margin: 1px auto; /* 15pcnt from the top and centered */
    padding: 20px;
    border: 1px solid #888;
    width: 850px; 
    border-radius: 5px;
    overflow-y:scroll;
  }

  .info-modal-content {
    background-color: #fefefe;
    margin: 1px auto; /* 15pcnt from the top and centered */
    padding: 20px;
    border: 1px solid #888;
    width: 850px; 
    height:400px;
    border-radius: 5px;
    overflow-y:scroll;
  }

  .info-modal {
    font-size: 18px;
  }

  /* two column layout */
  .column {
    float: left;
    width: 50%;
  }

  /* Clear floats after the columns */
  .row:after {
    content: "";
    display: table;
    clear: both;
  }

  /* Responsive layout - when the screen is less than 600px wide, make the two columns stack on top of each other instead of next to each other */
  @media screen and (max-width: 600px) {
    .column {
      width: 100%;
    }
  }

  .calibrationModal {
    width:400px;
  }

  .serialModal {
    height: 600px;
  }

  .dataModal {
    display:block !important;
    font-size: 12px;
  }

  .dataValue {
    
  }

  @media screen and (max-width: 800px) {
    .modal-content {
        width: 100vw;
      }
    }

  .file-upload-button {
    padding: 12px 0px;
    text-align: center;
  }
  
  .file-submit-button {
    padding: 12px 0px;
    text-align: center;
    font-size: 15px;
    padding: 6px 6px;
  }

  #capture-lift-data-button:active {
    background-color: #44b113;
  }

  .input_container {
    border: 1px solid #e5e5e5;
  }

  input[type=file]::file-selector-button {
    background-color: #fff;
    color: #000;
    border: 0px;
    border-right: 1px solid #e5e5e5;
    padding: 10px 15px;
    margin-right: 20px;
    transition: .5s;
  }

  input[type=file]::file-selector-button:hover {
    background-color: #eee;
    border: 0px;
    border-right: 1px solid #e5e5e5;
  }

  /* The Close Button */
  .closeDataModalButton, .closeInfoModalButton, .closeFileModalButton, .closeCaptureLiftDataModalButton, .closeSaveGraphDataModalButton, .closeLoadGraphDataModalButton, .closeExportGraphDataModalButton, .closeCalibrationModalButton, closeUpdateModalButton, closeFlowTargetModalButton {
    color: #aaa;
    float: right;
    font-size: 22px;
    font-weight: bold;
    cursor: pointer;
    height:40px;
    width:100%;
  }

  .closeFlowTargetModalButton:hover,
  .closeFlowTargetModalButton:focus,
  .closeUpdateModalButton:hover, 
  .closeUpdateModalButton:focus,
  .closeDataModalButton:hover, 
  .closeDataModalButton:focus,
  .closeFileModalButton:hover, 
  .closeFileModalButton:focus,
  .closeInfoModalButton:hover,
  .closeInfoModalButton:focus,
  .closeCaptureLiftDataModalButton:hover,
  .closeCaptureLiftDataModalButton:focus,
  .closeSaveGraphDataModalButton:hover,
  .closeSaveGraphDataModalButton:focus,
  .closeLoadGraphDataModalButton:hover,
  .closeLoadGraphDataModalButton:focus,
  .closeCalibrationModalButton:hover,
  .closeCalibrationModalButton:focus {
    color: black;
    text-decoration: none;
    cursor: pointer;
  }

  .fileSizeTxt{
    padding:10px;
  }

  .fileDelLink{
    padding:10px;
    left: 100px;
    cursor: pointer;
  }


  .file-link {
    cursor: pointer;
  }

  .fileListRow {
    margin-bottom: 10px;
    /* margin-top: 87px; */
  }

  .column {
    float: left;
    height: 40px;
  }

  .left {
    width: 350px;
    height: 40px;
  }

  .middle {
    width: 200px;
  }

  .right {
    width: 100px;
  }

  /* Clear floats after the columns */
  .row:after {
    content: "";
    display: table;
    clear: both;  
  }



  /***
   * Lift Graph
   */

  .graph-container {
    margin-top:50px;
    text-align: center;
  }

  svg.graph {
      height: 600px !important;
      width: 750px !important;
      background-color: #fff;
      padding-top: 100px;
      box-shadow: 2px 2px 12px 1px #666;
      stroke-linejoin: round;
  }

  svg.graph .grid {
    stroke: grey;
    stroke-dasharray: 1 2;
    stroke-width: 1;
  }

  svg.graph .points {
    /*stroke: white;*/
    stroke-width: 3;
  }
  svg.graph .first_set {
    fill: #00554d;
  }

  svg.graph .surfaces {
    fill-opacity: 0.5;
  }

  svg.graph .grid.double {
    stroke-opacity: 0.4;
  }

  svg.graph .labels {
    font-family: Arial;
    font-size: 14px;
    kerning: 1;
  }

  svg.graph .labels.x-labels {
    text-anchor: middle;
  }

  svg.graph .labels.y-labels {
    text-anchor: end;
  }



  .hide {
    display: none;
  }
      
  .dataCircle:hover + .hide {
    display: block;
    z-index: 999;
  }

  svg .dataCircle:hover {
    r: 6;
  }

  .dataCircle {
    position:relative;
    opacity: 0.25;
  } 

  .dataValue {
    text-anchor: middle;
    font-size: 14px;
    color: black;
    transition: font-size 0.5s, opacity 0.3s;    
  }






  /***
  * TESTS 
  */

  .prefTestOK {
    color: lightgreen; 
    font-size: 2.1rem;
    font-weight: bold;
  }

  .prefTestNOK {
    color: red; 
    font-size: 2.1rem;
    font-weight: bold;
  }




  /* radio button code */

  .switch-field {
    margin-top: 18px;
    margin-bottom: 18px;
  }

  .switch-field input {
    position: absolute !important;
    clip: rect(0, 0, 0, 0);
    height: 1px;
    width: 1px;
    border: 0;
    overflow: hidden;
  }

  .switch-field label {
    background-color: #989898;
    color: #FFF;
    font-size: 20px;
    line-height: 1;
    text-align: center;
    padding: 8px 8px;
    margin-right: -1px;
    box-shadow: inset 0 1px 3px rgba(0, 0, 0, 0.3), 0 1px rgba(255, 255, 255, 0.1);
    transition: all 0.1s ease-in-out;
  }

  .switch-field label:hover {
    cursor: pointer;
  }

  .switch-field input:checked + label {
    background-color: #44b113;
    box-shadow: none;
  }

  .switch-field label:first-of-type {
    border-radius: 4px 0 0 4px;
  }

  .switch-field label:last-of-type {
    border-radius: 0 4px 4px 0;
  }

  /* This is just for CodePen. */

  .form {
    max-width: 600px;
    font-family: "Lucida Grande", Tahoma, Verdana, sans-serif;
    font-weight: normal;
    line-height: 1.625;
    margin: 8px auto;
    padding: 16px;
  }



  #orifice-data {
    font-size: 22px;
    color: #666;
    margin-bottom: 18px;
  }

  /* radio button code */

  )CSS";

  return css;


}

