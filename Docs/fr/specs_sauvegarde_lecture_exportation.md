#Résumé.

L'objectif est d'enregistrer les projets, de les relire et de les exporter sous forme l'image.

#Contenu à enregistrer
-liste des objets graphiques
-leurs propriétés (couleurs, types d'arrondis,ext)
-leur position

enregistrer des propriétés pré-définies d'éléments.

#mode d'enregistrement
A définir
formation xml

#fichier de configuration
config.xml
<config>
   <cliparts>
      <clipart>path/img.jpg</clipart
      <clipart>path/img2.jpg</clipart>
   </cliparts>
   <boxes>//boites de styles préenregistrées en fonction des préférences des utilisateurs
      <box>
         <type>type</type>
         <color>blue</color>
         <property>round</property>
      </box>
   </boxes>
</config>

#fichier projet
<projet>
   <boxes>
      <boxe>
          <type>type</type>
          <position>xx;yy</position>
          <color>green</color>
          <property>rounded</property>
      </boxe>
   </boxes>
</project>


