
(cl:in-package :asdf)

(defsystem "rumba_msg-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "TargetPosition" :depends-on ("_package_TargetPosition"))
    (:file "_package_TargetPosition" :depends-on ("_package"))
  ))