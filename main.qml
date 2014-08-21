import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import net.khertan.documenthandler 1.0
import "Main.js" as Main

ApplicationWindow {
    visible: true
    width:  1024
    height: 700
    title:  "Hello World"

    property color normalTextColor: "wheat"
    property int evaluatedStart: -1
    property int evaluatedEnd: -1

    TextArea {
        id: textEditor
        x: 0; y: 0
        width: 800; height: 700;

        font.family: "Monaco"
        font.pixelSize: 20
        text: Main.initText
        style: TextAreaStyle {
            backgroundColor: "black"
            textColor: normalTextColor
        }

        function evaluateFwd() {
            var i = evaluatedStart+1;
            while (i < text.length) {
                if (text[i] !== '.')
                    i++;
                else {
                    console.log("Block is found:")
                    console.log(text.substring(evaluatedStart+1, i));
                    break;
                }
            }
            console.log("Can't find end of next block.")
        }
        function evaluateBwd() {

        }

        Keys.onPressed: {
            if ((event.modifiers & Qt.ControlModifier) && (event.key === Qt.Key_Down) ) {
                event.accepted = true;
                evaluateFwd();
            } else if ((event.modifiers & Qt.ControlModifier) && (event.key === Qt.Key_Up) ) {
                event.accepted = true;
                evaluateBwd();
            }
        }
    }

    DocumentHandler {
        id: documentHandler
        target: textEditor
        cursorPosition: textEditor.cursorPosition
        selectionStart: textEditor.selectionStart
        selectionEnd:   textEditor.selectionEnd
        Component.onCompleted: {
            documentHandler.setStyle(normalTextColor,
                                     "orange", "green",
                                     "green",
                                     textEditor.font.pixelSize);
            textEditor.forceActiveFocus();
        }
        onTextChanged: {
            textEditor.update()
        }
    }
}
