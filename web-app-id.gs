function doGet(e){
  var time2 = ""
  time2 = e.parameters.time2;
  save_data(time2);
  return ContentService.createTextOutput(time2);
}
function save_data(time2){
  var spr = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/your-google-sheet-ID/edit");
  var dataSheet = spr.getSheetByName("S_Data1");
  var row = dataSheet.getLastRow() + 1;
  dataSheet.getRange("A" + row).setValue(time2); 
}
