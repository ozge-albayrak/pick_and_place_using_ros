
(cl:in-package :asdf)

(defsystem "rumba_msg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "BatteryStatus" :depends-on ("_package_BatteryStatus"))
    (:file "_package_BatteryStatus" :depends-on ("_package"))
  ))