import QtQuick 2.9
import QtQuick.Controls 2.2

import inscription_board 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Scroll")

    property var controller: MainController

    Rectangle {
        id: headerBar

        width: parent.width
        height: 35

        color: "blue"

        Row {
            anchors.fill: parent

            Button {
                id: add
                height: parent.height
                width: height

                Image {
                    anchors.fill: parent
                    source: "images/cog.svg"

                    sourceSize.width: width
                    sourceSize.height: height
                }
            }

            Button {
                height: parent.height
                width: height

                Text {
                    anchors.fill: parent
                    text: "B"
                }
            }

            Button {
                height: parent.height
                width: height

                Text {
                    anchors.fill: parent
                    text: "C"
                }
            }
        }
    }

    ScrollView {
        anchors {
            top: headerBar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }

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
                        id: name
                        width: parent.width * 0.2
                        height: parent.height

                        color: (index % 2 == 0) ? "#aacbef" : "white"

                        Text {
                            anchors {
                                left: parent.left
                                leftMargin: 15
                                verticalCenter: parent.verticalCenter
                            }

                            text: model.QtObject.name
                        }
                    }

                    Rectangle {
                        id: licensedAdults
                        width: parent.width * 0.1
                        height: parent.height

                        color: name.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: model.QtObject.licensedAdults
                        }
                    }

                    Rectangle {
                        id: unlicensedAdults
                        width: parent.width * 0.1
                        height: parent.height

                        color: name.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: model.QtObject.unlicensedAdults
                        }
                    }

                    Rectangle {
                        id: licensedChildren
                        width: parent.width * 0.1
                        height: parent.height

                        color: name.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: model.QtObject.licensedChildren
                        }
                    }

                    Rectangle {
                        id: unlicensedChildren
                        width: parent.width * 0.1
                        height: parent.height

                        color: name.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: model.QtObject.unlicensedChildren
                        }
                    }

                    Rectangle {
                        id: childrenUnder7
                        width: parent.width * 0.1
                        height: parent.height

                        color: name.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: model.QtObject.childrenUnder7
                        }
                    }

                    Rectangle {
                        id: totalPrice
                        width: parent.width * 0.15
                        height: parent.height

                        color: name.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: Number(model.QtObject.totalPrice).toFixed(2) + " €" //TODO Currency format
                        }
                    }

                    Rectangle {
                        id: payment
                        width: parent.width * 0.15
                        height: parent.height

                        color: name.color

                        Text {
                            anchors {
                                centerIn: parent
                            }

                            text: "TODO Combobox"
                        }
                    }
                }
            }
        }
    }
}
