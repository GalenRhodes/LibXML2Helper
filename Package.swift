// swift-tools-version:5.2
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(name: "LibXML2Helper", products: [ .library(name: "LibXML2Helper", targets: [ "LibXML2Helper" ]) ], targets: [ .target(name: "LibXML2Helper", dependencies: []) ])
