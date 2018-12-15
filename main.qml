import QtQuick 2.9
import QtQuick.Controls 2.2

import inscription_board 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    property var controller: MainController

    ScrollView {
        anchors.fill: parent

        ListView {
            width: parent.width
            model: controller.mainListModel
            delegate: Item {
                width: parent.width
                height: 30

                Row {
                    spacing: 1
                    anchors.fill: parent

                    Rectangle {
                        id: textCell
                        width: parent.width * 0.7
                        height: parent.height

                        color: (index % 2 == 0) ? "#aacbef" : "white"

                        Text {
                            anchors {
                                left: parent.left
                                leftMargin: 15
                                verticalCenter: parent.verticalCenter
                            }

                            text: model.display
                        }

                        Component.onCompleted: {
                            console.log(qsTr("width #%1: %2 (%3)").arg(index + 1).arg(width).arg(parent.width))
                        }
                    }

                    Rectangle {
                        width: parent.width * 0.1
                        height: parent.height

                        color: textCell.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: "X"
                        }
                    }

                    Rectangle {
                        width: parent.width * 0.1
                        height: parent.height

                        color: textCell.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: "Y"
                        }
                    }

                    Rectangle {
                        width: parent.width * 0.1
                        height: parent.height

                        color: textCell.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: "Z"
                        }
                    }
                }
            }
        }
    }
}
