# Übungsaufgabe Nr. 3

Bevor Sie mit der Bearbeitung der ersten Übungsaufgabe starten wollen wir zunächst Ihre ``git`` Kenntnisse vertiefen. In den letzten Vorlesung Terminen haben Sie das Konzept der verschiedenen remotes kennengelernt. Dies wollen wir nun vertiefen. Am Ende verfügt Ihre lokale Arbeitskopie über mindestens zwei remotes. Aber zunächst alles der Reihe nach.

**WICHTIG:** Diese Übungsaufgabe soll einzeln und nicht in Gruppen erfolgen.

## Konfliktfrei

Aller Anfang ist schwer. Um sich das Leben nicht unnötig schwer zu machen sollten Sie den master Branch zunächst nicht ändern und jeweils immer nur die Änderungen aus dem allgemeinen Repository pullen. Das klare Ziel am Anfang ist es keine Konflikte zu provozieren.


**ACHTUNG:** Prüfen Sie ob ``origin`` Ihrer projekt URL entspricht! In dieser darf ``graugans`` nicht auftauchen!


## Anlegen der Branches

Bevor Sie anfangen Quellcode zu schreiben erzeugen sie zunächst eine Kopie des Branches für die erste Übungsaufgabe. Zunächst müssen wir allerdings die lokale Kopie unseres Repository mit `upstream` und Ihrem `origin` synchronisieren.  

```
git fetch --all
git checkout -b solution-003 upstream/exercise-003
```

Sie können mit dem Kommando ``git branch -a`` prüfen ob dies erfolgreich war:

```
  master
* solution-003
  remotes/origin/HEAD -> origin/master
  remotes/origin/master
  remotes/upstream/master
```
Damit Sie nicht aus versehen in das falsche Repository pushen müssen Sie git mitteilen, dass Sie ab jetzt in Ihren fork pushen wollen:

```
git push -u origin solution-003
```

Nun haben Sie den branch `main` aus meinem Repository in Ihren Fork übertragen.


## Der erste Commit

Um den ``git Workflow`` zu testen korrigieren Sie zunächst den [Schreibfehler in Zeile 11](exercise-002/main.cpp#L11).

### Änderungen in den Staging Bereich aufnehmen

Zum hinzufügen der Änderungen in den Staging Bereich nutzen Sie das Kommando ``git add -p``

### Übertragen der Änderungen in das lokale Repository

Das Übertragen oder auch ``commit`` genannt wird mit dem Kommando ``git commit`` durchgeführt. Sollte eine kurze commit Nachricht ausreichen können Sie dies direkt auf der Kommandozeile durchführen.

```
git commit -m "Fix typo in exercise-002"
```

### Übertragen der Änderungen in Ihren Fork

Damit diese Änderungen in Ihrem eigenen Fork sichtbar sind müssen diese gepusht werden.

```
git push -u origin solution-003
```

Nach der Übertragung können Sie im Web-Interface testen ob diese Änderung erfolgreich übernommen wurden.


# Aufgabenstellung

Implementieren Sie die fehlenden Code Teile

```cpp
// insert your code here....
```

## Nach getaner Arbeit

Haben Sie alle Punkte erfolgreich abgearbeitet erstellen Sie einen Pull-Request in Ihrem Fork und fügen mich ``graugans`` als Approval hinzu.

# Lernziele

- Vertiefung der git Kenntnisse
- Umgang mit Verkettenlisten
- Umgang mit der ``{fmt}`` Bibliothek